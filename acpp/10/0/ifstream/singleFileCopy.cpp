// System headers
#include <iostream>
#include <fstream>
#include <string>

// Local includes

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

// Typedefs, etc

int
main() {
    const char *infile = "/home/user/pf_letter.txt";
    const char *outfile = "outfile.txt";
    ifstream in(infile);
    ofstream out(outfile);
    string line;
    while (getline(in, line)) {
        out << line << "\n";
    }
    return 0;
}
