class Solution {
public:
    int maxDepth(string s) {
        int c = 0;
        int ans = 0;
        for(auto x:s){
            if(x=='('){
                c++;
                ans = max(ans,c);
            }
            if(x==')'){
                c--;
            }
        }
        return ans;
    }
};