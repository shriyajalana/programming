#include <iostream>
using namespace std;
void Double(int *A, int size)            //  *A == A[]
{
    int i;
    for (i = 0; i < size; i++)
    {
        A[i] = A[i]*2;                   // *(A+i) == A[i]
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int size = sizeof(A);    // sizeof(A[0]); //sizeof(A)=5*4->20; sizeof(A[0])=4; therefore the size is 20/4=5
    cout<<"size: "<<size<<endl;
    Double(A, size);         // A=&A[0]  This will pass the address of the first element
    int i;
    for (i = 0; i < size; i++)
    {
        cout << A[i] << "   ";
    }
    cout << endl;
    return 0;
}
