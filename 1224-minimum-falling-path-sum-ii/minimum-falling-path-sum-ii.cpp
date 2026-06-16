class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        vector<vector<int>> dp(m,vector<int>(m,0));
        for(int i=0;i<m;i++){
            dp[0][i]=grid[0][i];
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<m;j++){
                int a=INT_MAX;
                for(int k=0;k<m;k++){
                    if(k==j){
                        continue;
                    }
                    else{
                        a=min(a,dp[i-1][k]);
                    }
                }
                dp[i][j]=a+grid[i][j];
            }
        }
        int b=INT_MAX;
        for(int i=0;i<m;i++){
            b=min(b,dp[m-1][i]);
        }
        return b;
    }
};