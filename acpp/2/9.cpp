#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int
main() {
    int i, j;
    cout << "Enter 1st num : ";
    cin >> i;
    cout << "Enter 2nd num : ";
    cin >> j;
    cout << endl << "Max of above 2 nums is "
         << ( i > j ? i : j ) << endl;

    return 0;
}
