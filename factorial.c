#include<iostream>
using namespace std;
int main(){
    string n;
    int i;
    cin>>n;
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,k=0,l=0;
    for(i=0;i<n.length();i++){
        
        
        if(n[i]=='0'){
            a++;
        }
        if(n[i]=='1'){
            b++;
        }
        if(n[i]=='2'){
            c++;
        }
        if(n[i]=='3'){
            d++;
        }
         if(n[i]=='4'){
            e++;
        }
         if(n[i]=='5'){
            f++;
        }
         if(n[i]=='6'){
            g++;
        }
         if(n[i]=='7'){
            h++;
        }
         if(n[i]=='8'){
            k++;
        }
         if(n[i]=='9'){
            l++;
        }
    }
    cout<<"0"<<" "<<a<<"\n";
    cout<<"1"<<" "<<b<<"\n";
    cout<<"2"<<" "<<c<<"\n";
    cout<<"3"<<" "<<d<<"\n";
    cout<<"4"<<" "<<e<<"\n";
    cout<<"5"<<" "<<f<<"\n";
    cout<<"6"<<" "<<g<<"\n";
    cout<<"7"<<" "<<h<<"\n";
    cout<<"8"<<" "<<k<<"\n";
    cout<<"9"<<" "<<l<<"\n";
    
    


    return 0;
}
