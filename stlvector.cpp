#include<iostream>
#include<vector>
using namespace std;
int main()
{ int n;
cout<<"Enter Array Size \n";
cin>>n;
vector<int> a(n);int i,sum=0;
for(int i=0;i<a.size();i++)
	cin>>a[i];
for(int i=0;i<a.size();i++)
	cout<<endl<a[i];
 return 0;
}
