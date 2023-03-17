// System headers
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <list>
#include <algorithm>

// Local includes
#include "alienDictionary.h"

// Using declarations
using std::string;
using std::vector;
using std::list;
using std::unordered_map;
using std::queue;
using std::min;
using std::domain_error;

// Statics, typedefs, globals

class Graph {
public:
    Graph() { }

    // Adds given vertex to graph
    void
    addVertex(char c) {
        _inDegreeTbl[c] = 0;
        _adjList[c] = list<char>();
    }

    // Adds given edge to graph
    void
    addEdge(char s, char d) {
        _inDegreeTbl[d]++;
        _adjList[s].push_back(d);
    }

    // Removes given edge from graph
    void
    removeEdgeVirtual(char c, char d) {
        _inDegreeTbl[d]--;
    }

    // Returns true if given vertex has no incoming edges, false otherwise
    inline bool
    isSourceVertex(char c) {
        return _inDegreeTbl[c] == 0;
    }

    // List of neighbour vertices which can be reached from given vertex
    list<char>&
    neigbourVertices(char c) {
        return _adjList[c];
    }

    // Returns vector of source vertices (with nil incoming edges)
    vector<char>
    sourceVertices() {
        vector<char> cV;
        for (auto entry : _inDegreeTbl) {
            if (entry.second == 0) {
                cV.push_back(entry.first);
            }
        }
        return cV;
    }

    vector<char>
    topologicalOrdering() {

        // Add all source vertices to BFS queue
        queue<char> sourceQ;
        for (auto v : sourceVertices()) {
            sourceQ.push(v);
        }

        vector<char> topoSortV;
        // Till all source vertices all examined
        while (!sourceQ.empty()) {
            // Deque the source vertex at front of BFS Q and add it
            // to topological ordering
            char s = sourceQ.front();
            sourceQ.pop();
            topoSortV.push_back(s);

            // Remove the dequeued source vertex from graph (i.e. remove
            // all edges emanating from the vertex)
            for (auto d : neigbourVertices(s)) {
                removeEdgeVirtual(s, d);
                // Removal of edge (s, d) from source to neigbour results in
                // neigbour becoming a source, add neigbour to source Q
                if (isSourceVertex(d)) {
                    sourceQ.push(d);
                }
            }
        }

        // Mismatch in vertex nums
        // Cyclic dependency amongst edges, topological ordering not possible
        if (topoSortV.size() != _inDegreeTbl.size()) {
            return vector<char>();
        }

        return topoSortV;
    }

private:
    // Data members
    // Adjacency list table mapping each char to the list of chars it is
    // related with/prior to lexicographically 
    unordered_map<char, list<char> > _adjList;
    // Table which maintains number of incoming edges at each vertex
    unordered_map<char, unsigned> _inDegreeTbl;
};

vector<char>
AlienDict::dictionaryOrder(const vector<string>& dictWords) {
    if (dictWords.empty() || dictWords.size() == 1) {
        throw domain_error("Error! No input words/single word dict!");
    }

    // The lexicographic ordering of dictionary word characters
    // modelled as graph edges and graph vertices will be the characters

    // Iterate over all words and their respective characters to create graph
    Graph lexicalOrderingGraph;
    for (auto w : dictWords) {
        for (auto c : w) {
            lexicalOrderingGraph.addVertex(c);
        }
    }

    // Examine adjacent words in dictionary sequentially to determine
    // lexicographic ordering of characters. Construct graph edges with
    // lexicographic ordering
    typedef vector<string>::size_type vecSzT;
    for (vecSzT i = 1; i != dictWords.size(); ++i) {
        // Adjacent words
        string word1 = dictWords[i - 1];
        string word2 = dictWords[i];
        typedef string::size_type strSzT;
        // Examine adjacent words to determine first letters where they
        // differ and add the first letters to graph
        for (strSzT j = 0; j < min(word1.size(), word2.size()); ++j) {
            if (word1[j] != word2[j]) {
                lexicalOrderingGraph.addEdge(word1[j], word2[j]);
                break;
            }
        }
    }

    // Topological sort of graph vertices to determine the lexicographical
    // ordering of vertices/dictionary order
    vector<char> dictOrderV = lexicalOrderingGraph.topologicalOrdering();

    return dictOrderV;
}
