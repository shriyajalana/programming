// Count Digit
#include <iostream>
using namespace std;

int main()
{
    long long int n, count = 0, x;
    cin >> n;
    x = n;
    while (n != 0)
    {
        n = n / 10;
        count++;
    }
    cout << "digit in " << x << " is: " << count << endl;
    return 0;
}
