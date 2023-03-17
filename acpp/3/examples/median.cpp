#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::streamsize;
using std::setprecision;
using std::vector;
using std::sort;

int
main() {
    // Ask for student name
    string name;
    cout << "Please enter your name : ";
    cin >> name;
    cout << endl << "Hello " << name << " !" << endl;

    // Ask for midterm and final grades and store the same
    cout << "Please enter your midterm and final exam grades" << endl;
    double midterm, final;
    cin >> midterm >> final;

    // Ask for homework grades till eof and store all
    // the read homework grades in a vector
    cout << "Please enter all your homework grades "
         << "followed by end-of-file" << endl;

    vector<double> homework;
    double x;
    // Invariant : The vector homework contains the homework grades read so far
    while (cin >> x) {
        homework.push_back(x);
    }

    // Check that the student has entered at least some homework grades
    typedef vector<double>::size_type vecSzT;
    vecSzT size = homework.size();
    if (!size) {
        cout << "Error! Homework grades have not been entered! Exiting...!" << endl;
        return 1;
    }

    // Sort the vector of homework grades in nondecreasing order for computing
    // the median homework grade
    sort(homework.begin(), homework.end()); 

    // Compute the median of homework grades
    vecSzT mid = size / 2;
    double median =
        (size % 2 == 0) ?
        (homework[mid - 1] + homework[mid]) / 2 : homework[mid];

    // Compute and output the final grade
    streamsize prec = cout.precision();
    cout << endl << "The final grade is " << setprecision(3)
        << 0.4 * final + 0.2 * midterm + 0.4 * median
        << setprecision(prec) << endl;

    return 0;
}
