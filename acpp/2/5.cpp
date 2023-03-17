#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int
main() {
    int l, b;

    // 1. Square
    // Get params from user
    cout << "Enter side of square : ";
    cin >> l;
    // Separate input and output
    cout << endl;
    for (int i = 0; i != l; ++i) {
        cout << string(l, '*') << endl;
    }
    cout << endl;
    cout << endl;

    // 2. Rectangle
    // Get params from user
    cout << "Enter length of rectangle : ";
    cin >> l;
    cout << "Enter breadth of rectangle : ";
    cin >> b;
    // Separate input and output
    cout << endl;
    for (int i = 0; i != l; ++i) {
        cout << string(b, '*') << endl;
    }
    cout << endl;
    cout << endl;

    // 3. Triangle
    // Get params from user
    cout << "Enter height of triangle : ";
    cin >> l;
    cout << "Enter base of triangle : ";
    cin >> b;
    // Separate input and output
    cout << endl;
    const int aspectRatio = b / l;
    for (int i = 1; i <= l; ++i) {
        cout << string(i * aspectRatio, '*') << endl;
    }
    cout << endl;
    cout << endl;

    return 0;
}
