#include<iostream>
#include<list>
using namespace std;
void display(list<int> &li){
    list<int> :: iterator it;
    for(it=li.begin();it!=li.end();it++){
        cout<<*it<<"  ";
    }
    cout<<endl;
}
int main(){
    list<int> l;
    l.push_back(6);
    l.push_back(4);
    l.push_back(2);
    l.push_back(8);
    display(l);
    list<int> lis;
    list<int> :: iterator it;
    it=lis.begin();
    
    // vector<int> v;
    // v.push_back(5);
    // v.push_back(5);
    // cout<<(*max_element(v.begin(),v.end()))<<endl;
    // v[2]=7;
    // for(int i=0;i<v.size();i++){
    //     cout<<v.at(i)<<endl;
    // }
    // int i;
    // for(i=1;i<10;i++){
    //     v.push_back(i);
    // }
    // for(i=0;i<v.size();i++){
    //     cout<<v[i];
    // }
    // cout<<endl;
    // if(v.empty()){
    //     cout<<"vector is empty  \n";
    // }
    // else{
    //     cout<<"vector is not  empty\n";
    // }
    // cout<<endl;
    // cout<<"vector size is:  "<<v.size()<<"  vector capacity:  "<<v.capacity()<<"\n";
    return 0;
}
