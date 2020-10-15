#include<iostream>
using namespace std;
int main()
{
	int i,j,n;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		a[i]=a[i+1];
	}
	
	for(i=0;i<n;i++)
	{
		cout<<a[i];
	}
}
