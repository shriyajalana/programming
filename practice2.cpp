#include<iostream>
using namespace std;
int main()
{
	int i,n,d,t,j;
	cin>>t;
	while(t!=0)
	{
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
		{ 
			int count=0,l=0;
			l=i;
	for(j=i;j<n;j++)
		{
		if(a[l]>=a[i+1])
		{
			count++;
		}
		else 
			break;
		}
		if(count==(n-i))
		{
			cout<<a[i]<<" ";
		}
	}

	t--;
}
}

