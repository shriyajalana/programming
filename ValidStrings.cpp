class Solution {
    public:
    
        string getBinary(int num, int size){
            string binary="";
            while(num!=0){
                int rem=num%2;
                string stringVal=to_string(rem);
                binary=stringVal+binary;
                num/=2;
            }
            if(binary.size()!=size){
                int x=size-binary.size();
                while(x--){
                    binary="0"+binary;
                }
            }
            return binary;    
        }
        
        bool isValid(string s){
            for(int i=0;i<s.size();i++){
                if(i+1<s.size() && s[i]=='0' && s[i+1]=='0'){
                    return false;
                }
            }
            return true;
        }
    
        vector<string> validStrings(int n) {
            vector<string> result;
            if(n==1) return {"0", "1"};
            int maxInt=1;
            int powTwo=1;
            for(int i=1;i<n;i++){
                powTwo=powTwo*2;
                maxInt+=powTwo;
            }
            for(int i=0;i<=maxInt;i++){
                string binary=getBinary(i, n);
                if(isValid(binary)){
                    result.push_back(binary);
                }
            }
            
            return result;
        }
    };