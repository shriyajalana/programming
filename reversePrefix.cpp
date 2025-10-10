class Solution {
public:
    string reversePrefix(string word, char ch) {
        int charIdx=-1;
        for(int i=0;i<word.size();i++){
            if(word[i]==ch){
                charIdx=i;
                break;
            }
        }
        if(charIdx==-1) return word;
        int mid=charIdx/2;
        for(int low=0;low<=mid;low++){
            swap(word[low], word[charIdx]);
            charIdx--;
        }
        return word;
    }
};
