// find the given number is prime or Not prime
#include <iostream>
using namespace std;
int main()
{
    int n, i, j;
    cin >> n;
    for (j = 2; j <= n; j++)
    {
        for (i = 2; i < j; i++)
        {
            if (j % i == 0)
            {
                break;
            }
        }
        if (i == j)
        {
            cout << j << endl;
        }
    }
}
