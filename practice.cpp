#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> help(vector<int> &nums,vector<vector<int>> &v,vector<int> temp, int k,int idx){
  if(k<0){
    return v;
  }
  if(idx>=nums.size()){
    if(k==0){
      v.push_back(temp);
    }
    return v;
  }

  temp.push_back(nums[idx]);
  help(nums,v,temp,k-nums[idx],idx+1);
  temp.pop_back();
  help(nums,v,temp,k,idx+1);
  return v;
}

vector<vector<int>> solve(vector<int> &nums,int k){
  vector<vector<int>> v;
  vector<int> temp;
  return help(nums,v,temp,k,0);
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr); 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
  int n,k;
  cin>>n>>k;
  vector<int> v;
  for(int i=0;i<n;i++){
    int val;
    cin>>val;
    v.push_back(val);
  }
  vector<vector<int>> ans=solve(v,k);
  for(int i=0;i<ans.size();i++){
    for(auto it: ans[i]){
      cout<<it<<" ";
    }
    cout<<endl;
  }
  return 0;
}
