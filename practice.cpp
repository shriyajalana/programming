#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cin >> n;
    int pro = 1;
    for (i = 1; i <= n; i++)
    {
        pro = pro * i;
    }
    cout << pro << endl;
    return 0;
}

// int factorial(int n)
// {
//     if (n == 1)
//     {
//         return 1;
//     }
//     return n * factorial(n - 1);
// }
// int main()
// {
//     int n;
//     cin >> n;
//     cout << factorial(n) << endl;
// }
