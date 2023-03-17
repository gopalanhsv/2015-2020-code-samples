#include <iostream>
#include <vector>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::vector;
using std::domain_error;

double
average(const vector<double>& v) {
    if (0 == v.size()) {
        throw domain_error("average of empty vector");
    }

    // Iterate over all vector elements to compute the total
    double sum = 0.0;
    for (vector<double>::size_type i = 0; i != v.size(); ++i) {
        sum += v[i];
    }

    // Return the average of vector elements
    return sum / v.size();
}

istream&
read(istream& in, vector<double>& v) {
    if (in) {
        // Flush old data from vector
        v.clear();
        // Read data into vector till end of file
        // or incorrect input type encountered
        double x;
        while (in >> x)
            v.push_back(x);
        // Reset the input stream in case of issues
        in.clear();
    }
    return in;
}

int
main() {
    vector<double> vd;
    read(cin, vd);
    try {
        double avg = average(vd);
        cout << endl << "Avg of elements is = " << avg << endl;
    } catch (domain_error e) {
        cout << endl << e.what() << endl;
        return 1;
    }
    return 0;
}
