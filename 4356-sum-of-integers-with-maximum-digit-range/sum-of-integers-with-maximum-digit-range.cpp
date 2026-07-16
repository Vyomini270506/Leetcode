class Solution {
public:
    int r(int n){
        int s=n%10;
        int l=n%10;
        do{
            int rem = n%10;
            s=min(s,rem);
            l=max(l,rem);
            n=n/10;
        }while(n>0);
        return l-s;
    }
    int maxDigitRange(vector<int>& nums) {
        int ans=0;
        int f=0;
        for(auto x:nums){
            int y=r(x);
            if(y>ans){
                f=x;
                ans=y;
            }
            else if(y==ans){
                f=f+x;
            }
        }
        return f;
    }
};