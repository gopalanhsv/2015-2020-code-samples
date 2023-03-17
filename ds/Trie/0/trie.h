#ifndef _TRIE_H_
#define _TRIE_H_

// System headers
#include <vector>
#include <string>

// Local includes

// Using declarations

// Statics, typedefs, globals
class TrieNode;
typedef std::vector<TrieNode*>::size_type vecTNSzT;

class TrieNode {
public:
    // Constructor
    TrieNode();

    // Returns true if current trie node ends a word/key, false otherwise
    inline bool nodeEndsKey() { return _endsKey; }
    // Mark current trie node as ending a word/key
    inline void markNodeEndsKey() { _endsKey = true; }
    // Mark current trie node as not ending a word/key
    inline void unmarkNodeEndsKey() { _endsKey = false; }

    // Creates a trie node as child of given node at specified
    // index. Returns a pointer to the newly created child node
    TrieNode* createChildNode(vecTNSzT idx);
    // Deletes a trie node which is child of node at specified
    // index if it exists
    void deleteChildNode(vecTNSzT idx);
    // Returns a pointer to child of given node at specified index
    TrieNode* getChildNode(vecTNSzT idx);
    // Returns true if node has a child node
    bool hasChildren();

private:
    // Array of ptrs to child nodes hanging of current trie node
    std::vector<TrieNode*> _childPtrVec;
    // Indicates if current trie node ends a key/work or not
    bool _endsKey;
};

class Trie {
public:
    // Constructor
    Trie();
    // Destructor
    ~Trie();

    // Trie operations

    // Inserts the given key/word into the trie
    void insertNode(std::string key);
    // Searches for given key/word in the trie. Returns true
    // if key found, false otherwise
    bool searchNode(std::string key);
    // Deletes given key/word from the trie if present. Returns true
    // if key found and deleted, false if key not found
    bool deleteNode(std::string key);

private:
    // Returns index at which trie node representing given character
    // should be located at in its parent trie node
    vecTNSzT getTrieNodeIndex(char c);

    TrieNode* _root; // Root node of trie
};

#endif /* _TRIE_H_ */
