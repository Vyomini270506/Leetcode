class Solution {
public:
    bool isPowerOfTwo(int n) {
        int c=0;
        while(n>0){
            if(n%2==1){
                c++;
            }
            if(c>1){
                return false;
            }
            n=n/2;
        }
        if(c==1){
            return true;
        }
        return false;
    }
};