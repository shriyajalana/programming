#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string str;
    str = to_string(n);
    int k = str.length();
    cout << str[0] << "   " << str << "   " << k << endl;
    return 0;
}
