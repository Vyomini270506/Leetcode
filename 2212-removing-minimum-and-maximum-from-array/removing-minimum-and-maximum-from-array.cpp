class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mx = INT_MIN;
        int mxp = -1;
        int mn = INT_MAX;
        int mnp = -1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>mx){
                mx=nums[i];
                mxp=i;
            }
            if(nums[i]<mn){
                mn=nums[i];
                mnp=i;
            }
        }
        int left = min(mxp, mnp);
        int right = max(mxp, mnp);
        int ans1 = right + 1;
        int ans2 = n - left;
        int ans3 = left + 1 + n - right;
        return min({ans1, ans2, ans3});
    }
};