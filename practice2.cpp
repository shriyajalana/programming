#include<iostream>
#include<string>
using namespace std;
// bool checkPali(string s){
//     int l=0;
//     int h=s.size()-1;
//     while(l<=h){
//         if(s[l++]!=s[h--]){
//             return false;
//         }
//     }
//     return false;
// }
int main()
{
    string s;
    cin>>s;
    cout<<"Before: "<<s<<"After: ";
    cout<<s.erase(s.begin() + 4);
    return 0;
}
