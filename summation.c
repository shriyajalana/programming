//finding factorial of given number
#include<iostream>
int main()
{
	int n,i,p=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		p=p*i;
	}
	prinf("%d",p);
}
