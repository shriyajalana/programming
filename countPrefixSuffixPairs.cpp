class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2){
        int lstr1=str1.size();
        int lstr2 = str2.size();
        if(lstr1>lstr2) return false;
        if(str1==str2.substr(0, lstr1)){
            if(str1==str2.substr(lstr2-lstr1, lstr2)){
                return true;
            }
        }
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(isPrefixAndSuffix(words[i], words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};
