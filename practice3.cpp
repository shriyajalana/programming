// 1,2,3,6,4,5,7,6,9

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    vector<int> myVect;
    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        if (array[i] != k)
        {
            myVect.push_back(array[i]);
        }
    }
    cout << "Vector is: ";
    for (int j = 0; j < myVect.size(); j++)
    {
        cout << myVect[j] << ", ";
    }
    cout << endl;
}

// 1,2,3,4,5
