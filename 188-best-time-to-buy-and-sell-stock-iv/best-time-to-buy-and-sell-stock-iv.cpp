class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int t=k;t>0;t--){
                    if(j){
                        dp[i][j][t]=max(-prices[i]+dp[i+1][0][t],dp[i+1][1][t]);
                    }
                    else{
                        dp[i][j][t]=max(prices[i]+dp[i+1][1][t-1],dp[i+1][0][t]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};