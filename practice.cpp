#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a;
    while (n > 0)
    {
        int k = n % 2;
        a.push_back(k);
        n = n / 2;
    }
    for (int i = a.size() - 1; i >= 0; i--)
    {
        cout << a.at(i) << " ";
    }
    cout << endl;
    return 0;
}
