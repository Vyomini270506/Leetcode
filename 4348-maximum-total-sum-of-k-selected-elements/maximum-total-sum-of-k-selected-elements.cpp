class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(),greater<int>());
        long long ans=0;
        for(int i=0;i<k;i++){
            if(mul>0){
                ans+=(long long)nums[i]*(long long)mul;
                mul--;
            }
            else{
                ans+=(long long)nums[i];
            }
        }
        return ans;
    }
};