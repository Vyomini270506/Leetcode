class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        int m  = nums[0];
        int c = 0;
        for(auto x:nums){
            c+=x-m;
        }
        return c;
        
    }
};