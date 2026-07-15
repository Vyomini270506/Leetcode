class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long s = 0;
        for(int i=0;i<n;i++){
            int a = nums[i];
            int b = nums[i];
            for(int j=i;j<n;j++){
                a=max(a,nums[j]);
                b=min(b,nums[j]);
                s = s + (a-b);
            }
        }
        return s;
    }
};