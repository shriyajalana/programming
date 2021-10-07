#include <iostream>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    long long int a[10] = {0};
    while (n != 0)
    {
        long long int k = n % 10;
        a[k]++;
        n = n / 10;
    }
    for (long long int i = 0; i < 10; i++)
    {
        if (a[i] == 0)
        {
            continue;
        }
        else
        {
            cout << i << " :" << a[i] << "\n";
        }
    }
    cout << endl;
    return 0;
}
