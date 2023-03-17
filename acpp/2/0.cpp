#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int
main() {
    // Ask for username
    cout << "Please enter your name !";
    string name;
    cin >> name;

    // Create greeting
    const string greeting = "Hello " + name + "!";

    // Num blanks surrounding greeting
    const int pad = 2;
    // Compute num rows and cols of the frame
    const int rows = 3 + 2 * pad;
    const string::size_type cols = greeting.size() + 2 + 2 * pad;

    // Separate input and output
    cout << endl;

    // Invariant : We have written 'r' rows so far
    for (int r = 0; r != rows; ++r) {
        // Invariant : We have written 'c' cols so far in the rth row
        for (string::size_type c = 0; c != cols;) {
            // Is it time to write the greeting
            if (r == pad + 1 & c == pad + 1) {
                cout << greeting;
                c += greeting.size();
            } else { 
                // Are we at the border
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
                    cout << "*";
                } else {
                    cout << " ";
                }
                ++c;
            }
        }
        cout << endl;
    }
    return 0;
}
