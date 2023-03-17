#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::streamsize;
using std::setprecision;

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

    // Ask for homework grades till eof and maintain
    // the sum and count of homework grades
    cout << "Please enter all your homework grades "
         << "followed by end-of-file" << endl;

    double sum = 0, count = 0;
    double x;
    // Invariant : We have read count grades so far and sum has the
    // the total of the first count grades
    while (cin >> x) {
        ++count;
        sum += x;
    }

    // Compute and output the final grade
    streamsize prec = cout.precision();
    cout << endl << "The final grade is " << setprecision(3)
        << 0.4 * final + 0.2 * midterm + 0.4 * sum / count
        << setprecision(prec) << endl;

    return 0;
}
