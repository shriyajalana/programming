// This is the thing where you update everything regarding vectore
#include<iostream>
#include<vector>  // This is the headerfile of vector
using namespace std;
int main()
{ int n;
cout<<"Enter Array Size \n";
cin>>n;
vector<int> a(n);    // creating a a vector

int i,sum=0;
for(int i=0;i<a.size();i++)
{	cin>>a[i];	
	
}
a.push_back(10);
a.push_back(20);
cout<<"\nSize :\n"<<a.size();
for(int i=0;i<a.size();i++)
{
	cout<<endl<a[i];	
}
return 0;
}
