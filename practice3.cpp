#include<iostream>
#include<string.h>
using namespace std;

void print(char* c)            // c[i]==*(c+i)   &&    &c[i]==(c+i)              
{
    c[0]='k';
    while(*c!='\0')
    {
        cout<<*c;
        c++;
    }
    cout<<"\n";
}

int main()
{
    //char c[6]= {'a','f','r','o','z','\0'};
    char c[68]= "Afroziiitian";
    print(c);
}
