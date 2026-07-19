class Solution {
public:
    vector<vector<bool>> visited;
    void dfs(vector<vector<char>>& board,int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m){
            return;
        }
        
        if(visited[i][j] || board[i][j]=='X'){
            return;
        }

        visited[i][j]=true;

        dfs(board,i+1,j,n,m);
        dfs(board,i-1,j,n,m);
        dfs(board,i,j+1,n,m);
        dfs(board,i,j-1,n,m);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){ 
            
            dfs(board,i,0,n,m);
            dfs(board,i,m-1,n,m);
        }

        for(int i=0;i<m;i++){
            dfs(board,0,i,n,m);
            dfs(board,n-1,i,n,m);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]){
                    visited[i][j]=true;
                    if(
                        board[i][j]!='X'
                    ){
                        board[i][j]='X';
                    }
                }
            }
        }
    }
};