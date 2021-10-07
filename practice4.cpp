//Swaping two Number without introducing 3rd Variable
#include<iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	int c;
	c=a;
	a=b;
	b=c;
	cout<<"Swaped number is: "<<a<<b<<endl;
	return 0;
}
