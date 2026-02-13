class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int ri=0;
        int ci=col-1;
        int count=0;
        while(ri<row && ci>=0){
            int el = grid[ri][ci];
            if(el < 0){
                count += row - ri;
                ci--;
            }
            else{
                ri++;
            }
        }
        return count;
    }
};