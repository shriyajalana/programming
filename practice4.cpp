//Swaping two Number without introducing 3rd Variable
#include<iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;  //if a=3,b=4
	a=a+b;     //a=7 b=4
	b=a-b;     // a=7 b=3
	a=a-b;     //a=4 b=3
	cout<<"Swaped:  "<<a<<b;  //Successfully swaped both number
	return 0;
}
