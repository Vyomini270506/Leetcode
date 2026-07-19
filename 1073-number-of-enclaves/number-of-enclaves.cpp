class Solution {
public:
    vector<vector<bool>> vis;
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m){
        
        if(i<0 || j<0 || i>=n || j>=m){
            return;
        }

        if(vis[i][j] || grid[i][j]==0){
            return;
        }

        vis[i][j]=true;
        dfs(grid,i+1,j,n,m);
        dfs(grid,i-1,j,n,m);
        dfs(grid,i,j+1,n,m);
        dfs(grid,i,j-1,n,m);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vis = vector<vector<bool>> (n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            dfs(grid,i,0,n,m);
            dfs(grid,i,m-1,n,m);
        }

        for(int i=0;i<m;i++){
            dfs(grid,0,i,n,m);
            dfs(grid,n-1,i,n,m);
        }

        int c = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] &&  grid[i][j]==1){
                    c++;
                    grid[i][j]=0;
                }
            }
        }

        return c;
    }
};