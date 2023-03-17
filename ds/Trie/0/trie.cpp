// System headers
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <cctype>
#include <stack>

// Local includes
#include "trie.h"

// Using declarations
using std::vector;
using std::stack;
using std::string;
using std::domain_error;
using std::transform;
using std::find_if;

// Statics, typedefs, globals

// Max length of a trie key/word
const vector<TrieNode*>::size_type MaxKeySpace = 26;

//////////////////////// TRIE NODE CLASS ///////////////////////////////////

// Constructor
TrieNode::TrieNode() : _childPtrVec(MaxKeySpace, nullptr), _endsKey(false) {
}

// Creates a trie node as child of given node at specified index if it does
// not exist. Returns a pointer to the newly created child node
TrieNode*
TrieNode::createChildNode(vecTNSzT idx) {
    if (idx >= MaxKeySpace) {
        throw domain_error("Error! Invalid idx in createChildNode()!");
    }

    if (nullptr == _childPtrVec[idx]) {
        _childPtrVec[idx] = new TrieNode();
    }

    return _childPtrVec[idx];
}

// Deletes a trie node which is child of node at specified index if it exists
void
TrieNode::deleteChildNode(vecTNSzT idx) {
    if (idx >= MaxKeySpace || nullptr == _childPtrVec[idx]) {
        throw domain_error("Error! Invalid idx in deleteChildNode()!");
    }

    delete _childPtrVec[idx];
    _childPtrVec[idx] = nullptr;
}

// Returns a pointer to child of given node at specified index
TrieNode*
TrieNode::getChildNode(vecTNSzT idx) {
    if (idx >= MaxKeySpace) {
        throw domain_error("Error! Invalid idx in getChildNode()!");
    }
    return _childPtrVec[idx];
}

// Returns true if node has a child node
bool
notNullTrieNode(TrieNode* ptr) {
    return ptr != nullptr;
}

bool
TrieNode::hasChildren() {
    return (find_if(_childPtrVec.begin(),
        _childPtrVec.end(), notNullTrieNode) != _childPtrVec.end());
}

///////////////////// END TRIE NODE CLASS //////////////////////////////////

/////////////////////////// TRIE CLASS ///////////////////////////////////

// Constructor
Trie::Trie() : _root(new TrieNode()) {
}

Trie::~Trie() {
    // Delete all trie nodes from current trie
    // Set root as null
    delete _root;
    _root = nullptr;
}

// Returns index at which trie node representing given character should
// be located at in its parent trie node
vecTNSzT
Trie::getTrieNodeIndex(char c) {
    if (c < 'a' || c > 'z') {
        throw domain_error("Error! Invalid key char in getTrieNodeIndex()!");
    }
    return c - 'a';
}

// Inserts the given key/word into the trie
void
Trie::insertNode(string key) {
    if (key.empty()) {
        throw domain_error("Error! Empty key in insertNode()!");
    }
    // Convert key/word to lowercase
    transform(key.begin(), key.end(), key.begin(), tolower);

    TrieNode* currNode = _root;
    // Iterate over all chars of given key sequentially.
    string::const_iterator it = key.begin();
    string::const_iterator endIt = key.end();
    for (; it != endIt; ++it) {
        char c = *it;
        // Get index at which trie node representing current character is
        // located as a child in the current parent trie node
        vecTNSzT idx = getTrieNodeIndex(c);
        // For each char which does not have a corresponding node in the trie, create a
        // new trie node as appropriately indexed child of current node 
        TrieNode* childNode = currNode->createChildNode(idx);
        currNode = childNode;
    }

    // Mark the bottom most node as ending key
    currNode->markNodeEndsKey();
}

// Searches for given key/word in the trie. Returns true
// if key found, false otherwise
bool
Trie::searchNode(string key) {
    if (key.empty()) {
        throw domain_error("Error! Empty key in searchNode()!");
    }
    // Convert key/word to lowercase
    transform(key.begin(), key.end(), key.begin(), tolower);

    // Iterate over all chars of given key sequentially. For each char
    // which does not have a corresponding node in the trie, create a
    // new trie node as appropriately indexed child of current node 
    TrieNode* currNode = _root;
    string::const_iterator it = key.begin();
    string::const_iterator endIt = key.end();
    for (; it != endIt; ++it) {
        char c = *it;
        // Get index at which trie node representing current character is
        // located as a child in the current parent trie node
        vecTNSzT idx = getTrieNodeIndex(c);
        // Get the child node. If null, no trie node for current char
        // and hence key is not present
        TrieNode* childNode = currNode->getChildNode(idx);
        if (!childNode) {
            return false;
        }
        currNode = childNode;
    }

    // If last char of key is either not represented by a trie node or
    // fails to mark the end of a key, given key doesn't exist in trie
    if (!currNode || !currNode->nodeEndsKey()) {
        return false;
    }

    return true;
}

// Deletes given key/word from the trie if present. Returns true
// if key found and deleted, false if key not found
bool
Trie::deleteNode(string key) {
    if (key.empty()) {
        throw domain_error("Error! Empty key in deleteNode()!");
    }
    // Convert key/word to lowercase
    transform(key.begin(), key.end(), key.begin(), tolower);

    // Trie Node deletion technique would be to start from trie root,
    // sequentially iterate over all characters of the key and use the
    // key chars to visit corresponding trie node till the last char
    // is processed. Then we retrace the path from last trie node for key
    // back upto the root (deleting each trie node on the way) till a
    // node is reached which is part of another key

    // For retracing path, will have to use a stack/recursion to store
    // each parent trie node and index of child trie node representing
    // the current character of the key
    // Structure for retracing trie key path
    typedef struct _keyPathEntry {
        TrieNode *parentNode;
        vecTNSzT childIdx;
    } keyPathEntryT;

    stack<keyPathEntryT> pathStack;
    // Iterate over all chars of given key sequentially.
    TrieNode* currNode = _root;
    string::const_iterator it = key.begin();
    string::const_iterator endIt = key.end();
    for (; it != endIt; ++it) {
        char c = *it;
        // Get index at which trie node representing current character is
        // located as a child in the current parent trie node
        vecTNSzT idx = getTrieNodeIndex(c);

        // Add current parent node and child trie node index for the key
        // to stack for retracing path
        keyPathEntryT kpe;
        kpe.childIdx = idx;
        kpe.parentNode = currNode;
        pathStack.push(kpe);

        // Get the child node. If null, no trie node for current char
        // and hence key is not present
        TrieNode* childNode = currNode->getChildNode(idx);
        if (!childNode) {
            return false;
        }
        currNode = childNode;
    }

    if (!currNode || !currNode->nodeEndsKey()) {
        // Last char of key is either not represented by a trie node or
        // fails to mark the end of a key, given key doesn't exist in trie
        return false;
    } else {
        // Given key exists in trie. Unmark trie node for last character
        // as not ending key/work to commence deletion
        currNode->unmarkNodeEndsKey();
    }

    // Retrace path of key up back to root till a node is encountered
    // which is part of another key
    while (!pathStack.empty()) {
        // Pop an entry off the stack
        keyPathEntryT kpe = pathStack.top();
        pathStack.pop();

        TrieNode* parentNode = kpe.parentNode;
        TrieNode* childNode = parentNode->getChildNode(kpe.childIdx);
        // If child trie node is part of another key, it will either
        // end some key or have child(ren) (after unmarking/deletion of
        // current key trie nodes), so exit
        if (childNode->hasChildren() || childNode->nodeEndsKey()) {
            break;
        }
        // Delete the child node as its not part of another key
        parentNode->deleteChildNode(kpe.childIdx);
    }

    return true;
}

//////////////////////// END TRIE CLASS ///////////////////////////////////
