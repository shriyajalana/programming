// fibonacci series up to given number
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        cout << "fib: " << i << " is: " << fib[i] << endl;
    }
    return 0;
}

// int fib(int n){
//     if(n<2){
//         return n;
//     }
//     return fib(n-1)+fib(n-2);
// }

// int main(){
//     int n;
//     cin>>n;
//     cout<<fib(n)<<endl;
//     return 0;
// }
