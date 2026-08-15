class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int x = nums[0];
        bool allZ = true;

        if (nums[0] != 0)
            allZ = false;

        for (int i = 1; i < n; i++) {
            x ^= nums[i];

            if (nums[i] != 0)
                allZ = false;
        }

        if (allZ)
            return 0;

        if (x != 0)
            return n;

        return n - 1;
    }
};