class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        set<pair<int,int>> live;
        set<pair<int,int>> dead;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==1){
                    int c=0;
                    if(j-1>=0 && board[i][j-1]==1){
                        c++;
                    }
                    if(j+1<=m-1 && board[i][j+1]==1){
                        c++;
                    }
                    if(i-1>=0 && board[i-1][j]==1){
                        c++;
                    }
                    if(i+1<=n-1 && board[i+1][j]==1){
                        c++;
                    }
                    if(j-1>=0 && i-1>=0 && board[i-1][j-1]==1){
                        c++;
                    }
                    if(j+1<=m-1 && i-1>=0 && board[i-1][j+1]==1){
                        c++;
                    }
                    if(j-1>=0 && i+1<=n-1 && board[i+1][j-1]==1){
                        c++;
                    }
                    if(j+1<=m-1 && i+1<=n-1 && board[i+1][j+1]==1){
                        c++;
                    }
                    if(c<2 || c>3){
                        live.insert({i,j});
                    }
                }
                else{
                    int c=0;
                    if(j-1>=0 && board[i][j-1]==1){
                        c++;
                    }
                    if(j+1<=m-1 && board[i][j+1]==1){
                        c++;
                    }
                    if(i-1>=0 && board[i-1][j]==1){
                        c++;
                    }
                    if(i+1<=n-1 && board[i+1][j]==1){
                        c++;
                    }
                    if(j-1>=0 && i-1>=0 && board[i-1][j-1]==1){
                        c++;
                    }
                    if(j+1<=m-1 && i-1>=0 && board[i-1][j+1]==1){
                        c++;
                    }
                    if(j-1>=0 && i+1<=n-1 && board[i+1][j-1]==1){
                        c++;
                    }
                    if(j+1<=m-1 && i+1<=n-1 && board[i+1][j+1]==1){
                        c++;
                    }
                    if(c==3){
                        dead.insert({i,j});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(live.find({i,j}) != live.end()){
                    board[i][j]=0;
                }
                if(dead.find({i,j}) != dead.end()){
                    board[i][j]=1;
                }
            }
        }
    }
};