class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            map<string, vector<string>> mymap;
            for(int i=0;i<strs.size();i++){
                string sortedStr = strs[i];
                sort(sortedStr.begin(), sortedStr.end());
                if(mymap.count(sortedStr)){
                    vector<string> x = mymap[sortedStr];
                    x.push_back(strs[i]);
                    mymap[sortedStr] = x;
                }else{
                    vector<string> vs;
                    vs.push_back(strs[i]);
                    mymap[sortedStr] = vs;
                }
            }
            vector<vector<string>> result;
            for(auto x: mymap){
                result.push_back(x.second);
            }
            return result;
        }
    };