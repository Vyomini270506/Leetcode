class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        int x=k%m;
        vector<vector<int>> og;
        og=mat;
        while(x){
            for(int i=0;i<n;i++){
            if(i%2==0){
                int y=mat[i][0];
                 for(int j=0;j<m-1;j++){
                    mat[i][j]=mat[i][j+1];
                }   
                mat[i][m-1]=y;
            }
            else{
                int y=mat[i][m-1];
                for(int j=m-1;j>0;j--){
                    mat[i][j]=mat[i][j-1];
                }
                mat[i][0]=y;
            }
        }
        x--;
        }
        return og==mat;
    }
};