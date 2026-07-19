class Solution {
public:
    void dfs(vector<vector<int>>& image,int i,int j,int n,int m,int col,int ncol){
        if(i<0 || i>=n || j<0 || j>=m || image[i][j]!=col){
            return;
        }
        
        int x = image[i][j];
        image[i][j] = ncol;
        dfs(image,i+1,j,n,m,x,ncol);
        dfs(image,i-1,j,n,m,x,ncol);
        dfs(image,i,j+1,n,m,x,ncol);
        dfs(image,i,j-1,n,m,x,ncol);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n =image.size();
        int m=image[0].size();
        if (image[sr][sc] == color) {
            return image;
        }
        dfs(image,sr,sc,n,m,image[sr][sc],color);
        
        return image;
    }
};