class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = INT_MAX;
        int n = nums.size();
        int low = 0;
        int high = 0;
        int t = 0;
        while(low<n && high<n){
            t+=nums[high];
            while(t>=target){
                l = min(l,high-low+1);
                t-=nums[low];
                low++;
            }
            high++;
        }
        if(l==INT_MAX) return 0;
        return l;
    }
};