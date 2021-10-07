// 2^3=8
#include <iostream>
using namespace std;
int main()
{
    int x, n;
    long long int val = 1;
    cin >> x >> n;
    while (n-- > 0)
    {
        val = val * x;
    }
    cout << val << endl;
    return 0;
}
