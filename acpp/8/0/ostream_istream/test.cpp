// System headers
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>

// Local includes

// Using declarations
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::string;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;

// Typedefs

template<class T>
void
displayContainerElements(const T& c, ostream& os) {
    typedef typename T::const_iterator IterT;
    for (IterT i = c.begin(); i != c.end(); ++i) {
        os << *i << endl;
    }
}

template<class T>
void
copyIntoContainer(istream& in, T& c) {
    if (in) {
        c.clear();
        typename T::value_type x;
        while (in >> x) {
            c.push_back(x);
        }
        in.clear();
    }
}

template<class T>
void
copyIntoContainerViaIterator(istream& in, T& c) {
    if (in) {
        c.clear();
        typedef typename T::value_type ValTypeT;
        copy(istream_iterator<ValTypeT>(in),
            istream_iterator<ValTypeT>(), back_inserter(c));
        in.clear();
    }
}

int
main() {
    /// TEST 1
    vector<int> v1;
    copyIntoContainer(cin, v1);
    cout << "Displaying via loop" << endl;
    displayContainerElements(v1, cout);
    cout << "Displaying via ostream_iterator" << endl;
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, "\n"));

    /// TEST 2
    vector<string> v2;
    copyIntoContainer(cin, v2);
    cout << "Displaying via loop" << endl;
    displayContainerElements(v2, cout);
    cout << "Displaying via ostream_iterator" << endl;
    copy(v2.begin(), v2.end(), ostream_iterator<string>(cout, "\n"));

    /// TEST 3
    copyIntoContainerViaIterator(cin, v1);
    cout << "Displaying via loop" << endl;
    displayContainerElements(v1, cout);
    cout << "Displaying via ostream_iterator" << endl;
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, "\n"));

    /// TEST 4
    copyIntoContainerViaIterator(cin, v2);
    cout << "Displaying via loop" << endl;
    displayContainerElements(v2, cout);
    cout << "Displaying via ostream_iterator" << endl;
    copy(v2.begin(), v2.end(), ostream_iterator<string>(cout, "\n"));

    return 0;
}
