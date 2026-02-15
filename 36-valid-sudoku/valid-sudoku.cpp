class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(auto a:board){
            vector<int> row(10,0);
            for(auto x:a){
                if(x=='.') continue;
                int y=x-'0';
                if(row[y]!=0) return false;
                row[y]=1;
            }            
        }
        for(int i=0;i<9;i++){
            vector<int> col(10,0);
            for(int j=0;j<9;j++){
                char x=board[j][i];
                if(x=='.') continue;
                int y=x-'0';
                if(col[y]!=0) return false;
                col[y]=1;
            } 
        }
        for(int br=0;br<9;br+=3){
            for(int bc=0;bc<9;bc+=3){
                vector<int> box(10,0);
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        char x = board[br+i][bc+j];
                        if(x=='.') continue;
                        int y = x-'0';
                        if(box[y]) return false;
                        box[y] = 1;
                    }
                }
            }
        }

        return true;
    }
};