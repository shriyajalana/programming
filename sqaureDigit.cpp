class Solution {
    public:
    
        int squareDigit(int n){
            int sum=0;
            while(n){
                int x=n%10;
                sum=sum+(x*x);
                n=n/10;
            }
            return sum;
        }
        bool isHappy(int n) {
            map<int, int> mp;
            while(!(mp.find(n)!=mp.end())){
                mp[n]=1;
                n=squareDigit(n);
                if(n==1) return true;
            }
            return false;
        }
    };