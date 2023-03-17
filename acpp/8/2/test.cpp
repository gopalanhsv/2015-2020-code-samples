// System headers
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>

// Local includes
#include "algorithm.h"

// Using declaration
using std::list;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;
using std::ostream_iterator;
using std::istream_iterator;
using std::back_inserter;

void
testAccumulate(istream& in, ostream& os) {
    int x;
    vector<int> v;
    while (in >> x) {
        v.push_back(x);
    }
    in.clear();
    os << "Accumulate (int) = " << accumulate(v.begin(), v.end(), 0) << endl; ;

    double x1;
    vector<double> v1;
    while (in >> x1) {
        v1.push_back(x1);
    }
    in.clear();
    os << "Accumulate (double) = " << accumulate(v1.begin(), v1.end(), 0.0) << endl; ;

    string x2;
    vector<string> v2;
    while (in >> x2) {
        v2.push_back(x2);
    }
    x2 = "";
    in.clear();
    os << "Accumulate (string) = " << accumulate(v2.begin(), v2.end(), x2) << endl; ;
}

bool
lessThan100(int x) {
    return (x < 100);
}

bool
lessThanEqualTo0(int x) {
    return (x < 0);
}

void
testPartition(istream& in, ostream& os) {
    vector<int> v;
    mycopy(istream_iterator<int>(in), istream_iterator<int>(),
        back_inserter(v));
    in.clear();
    os << "Partition (int) lessThan100" << endl; ;
    vector<int>::iterator i = partition(v.begin(), v.end(), lessThanEqualTo0);
    os << "Pivot point val is " << *i << endl;
    mycopy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    os << endl;
}

void
testEqual(istream& in, ostream& os) {
    string s;
    getline(in, s);
    in.clear();
    os << "Testing equal for above is " <<
        myequal(s.begin(), s.end(), s.rbegin()) << endl;
}


void
testSearch(istream& in, ostream& os) {
    os << "Enter string in which to search : ";
    string s;
    getline(in, s);
    in.clear();

    os << "Enter sequence to search : ";
    string seq;
    in >> seq;
    in.clear();

    string::iterator i = search(s.begin(), s.end(), seq.begin(), seq.end());
    if (i != s.end()) {
        os << "Sequence found in string at " << i - s.begin() <<
            " chars from beginning" << endl;
    } else {
        os << "Sequence not found" << endl;
    }
}

int
transformToTrueForGT400(int x) {
    return x > 400 ? 1 : 0;
}

void
testTransform(istream& in, ostream& os) {
    vector<int> v;
    mycopy(istream_iterator<int>(in), istream_iterator<int>(),
        back_inserter(v));
    in.clear();
    vector<int> v1;
    os << "Transform to true for >400" << endl; ;
    transform(v.begin(), v.end(), back_inserter(v1), transformToTrueForGT400);
    mycopy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    os << endl;
}

void
testRemoveCopy(istream& in, ostream& os) {
    list<string> ls;
    os << "Enter sequence of strings : " << endl; ;
    mycopy(istream_iterator<string>(in), istream_iterator<string>(),
        back_inserter(ls));
    in.clear();

    vector<string> vs;
    string s;
    os << "Enter value not to be copied " << endl; ;
    in >> s;
    remove_copy(ls.begin(), ls.end(), back_inserter(vs), s);
    mycopy(vs.begin(), vs.end(), ostream_iterator<string>(cout, " "));
    os << endl;

    list<int> v;
    os << "Enter sequence of integers : " << endl; ;
    mycopy(istream_iterator<int>(in), istream_iterator<int>(),
        back_inserter(v));
    in.clear();

    vector<int> v1;
    int x;
    os << "Enter value not to be copied " << endl; ;
    in >> x;
    remove_copy(v.begin(), v.end(), back_inserter(v1), x);
    mycopy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    os << endl;
}

void
testRemove(istream& in, ostream& os) {
    list<string> ls;
    os << "Enter sequence of strings : " << endl; ;
    mycopy(istream_iterator<string>(in), istream_iterator<string>(),
        back_inserter(ls));
    in.clear();

    string s;
    os << "Enter value not to be copied " << endl; ;
    in >> s;
    list<string>::iterator i = remove(ls.begin(), ls.end(), s);
    mycopy(ls.begin(), i, ostream_iterator<string>(cout, " "));
    os << endl;
}

int
main() {
    //testAccumulate(cin, cout);
    //testPartition(cin, cout);
    //testEqual(cin, cout);
    //testSearch(cin, cout);
    //testTransform(cin, cout);
    //testRemoveCopy(cin, cout);
    testRemove(cin, cout);
    return 0;
}
