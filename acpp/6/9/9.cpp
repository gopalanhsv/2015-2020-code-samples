// System includes
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

// Loca includes

// Using declarations
using std::string;
using std::vector;
using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::accumulate;

string
concatenateVecStr(const vector<string>& v) {
    string cs;
    return accumulate(v.begin(), v.end(), cs);
}

istream&
readVec(istream& in, vector<string>& v) {
    if (in) {
        v.clear();
        string x;
        while (in >> x)
            v.push_back(x);
        in.clear();
    }
    return in;
}

int
main() {
    // Read a vector of strings from input
    vector<string> words;
    readVec(cin, words);

    // Separate input and output
    cout << endl;

    // Concatenate all string in the vector and display
    cout << concatenateVecStr(words) << endl; 

    return 0;
}
