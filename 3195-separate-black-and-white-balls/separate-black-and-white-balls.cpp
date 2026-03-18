class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        long long a=0;
        long long b=0;
        for(auto x:s){
            if(x=='1'){
                a++;
            }
            else{
                b+=a;
            }
        } 
        return b;
    }
};