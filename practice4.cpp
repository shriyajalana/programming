// GCD of Two Numbers
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int gcd;
    if (n > m)
    {
        for (int i = 1; i < n / 2; i++)
        {
            if (n % i == 0 && m % i == 0)
            {
                gcd = i;
            }
        }
    }
    else
    {
        for (int i = 1; i < m / 2; i++)
        {
            if (n % i == 0 && m % i == 0)
            {
                gcd = i;
            }
        }
    }
    cout << "Gcd is: " << gcd << endl;
}
