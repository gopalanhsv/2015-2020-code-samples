// System headers
#include <vector>
#include <iostream>
#include <stdexcept>

// Local includes
#include "meetingRoom.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;

// Statics, globals, typedefs

void
readVec(vector<Meeting>& v) {
    v.clear();
    cout << "Enter number of meetings : ";
    int n;
    cin >> n;
    while (n--) {
        int s, e;
        cout << endl << "Enter meeting start time : ";
        while (!(cin >> s));
        cout << endl << "Enter meeting end time : ";
        while (!(cin >> e));
        v.push_back({s, e});
    }
}

void
printVec(const vector<Meeting>& mv) {
    cout << endl;
    for (auto m : mv) {
        cout << "[ " << m.start() << ", " << m.end() << "] " << endl;
    }
    cout << endl;
}

void
testFn() {
    vector<Meeting> mv;
    readVec(mv);
    cout << "Input meetings are : ";
    printVec(mv);
    int n = MeetingRooms::findMinimumRequired(mv);
    cout << "Minimum of " << n <<
        " rooms required to conduct meetings" << endl;
}

int
main() {
    try {
        testFn();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
