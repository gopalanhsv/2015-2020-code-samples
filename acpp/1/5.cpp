#include <iostream>
#include <string>

using namespace std;

int
main() {
    {
        string s = "a string";
        {
            string x = s + ", really";
            cout << x << endl;
        }
        cout << s << endl;
    }
    
    return 0;
}
