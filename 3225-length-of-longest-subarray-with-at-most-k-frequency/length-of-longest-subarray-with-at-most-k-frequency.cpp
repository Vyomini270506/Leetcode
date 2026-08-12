class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int low = 0;
        int n = nums.size();
        int bad = 0;
        map<int,int> f;
        int ans = INT_MIN;
        for(int high=0;high<n;high++){
            f[nums[high]]++;
            if(f[nums[high]] == k + 1){
                bad++;
            }
            while(bad>0){
                if(f[nums[low]]==k + 1){
                    bad--;
                }              
                f[nums[low]]--;
                low++;
                
            }
            ans = max(ans,high-low+1);
        }
        return ans;    
    }
};