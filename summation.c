#include <iostream>
using namespace std;

void lowerBound(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int mid;
    int index = -1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            index = mid;
            break;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (index == -1)
    {
        cout << "lowerBound is: " << low << endl;
    }
    else
    {
        cout << "element is present " << index << endl;
    }
}

void UpperBound(int arr[], int n, int target)
{
    int low = 0;
    int high = n;
    int mid;
    int index = -1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            index = mid;
            break;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (index == -1)
    {
        cout << low << endl;
    }
    else
    {
        cout << index + 1 << endl;
    }
}
int main()
{
    int arr[] = {4, 7, 13, 24, 45, 56, 67, 439};
    int low = 0;
    int n = 8;
    int high = 7;
    int mid;
    int target = 5;
    int result = -1;
    lowerBound(arr, n, 48);  //lowerBound return if element is present otherwise next greater element
    UpperBound(arr, n, 439); //lowerBound return if element is present otherwise next greater element
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            result = mid;
            break;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (result == -1)
    {
        cout << "not present\n";
    }
    else
    {
        cout << "Element present at index " << result << " and element is " << arr[result] << endl;
    }
    return 0;
}
