#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,i,temp;
    cin>>n;
    vector<int> vect;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        vect.push_back(temp);
    }
    //vect(begin(arr),end(arr));
    cout<<endl;
    for(i=0;i<vect.size();i++)
    {
        cout<<vect[i]<<" ";
    }
    return 0;
}
