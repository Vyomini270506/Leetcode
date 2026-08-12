class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int c = 0;
        unordered_map<int,int> f;
        int sum = 0;
        f[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum - k;
            c += f[rem];
            f[sum]++;
        }

        return c;
    }
};