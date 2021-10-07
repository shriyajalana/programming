#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        int a[n];
        int i;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int x,sum=0;

        for(i=0;i<n;i++)
        {
            if(i==n-1 && (n!=2))
            {
                x=a[i]-a[0];
                x=abs(x);
                sum=sum+x;              
            }
            if(i<n-1)
            {
                x=a[i]-a[i+1];
                x=abs(x);
                sum=sum+x;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
