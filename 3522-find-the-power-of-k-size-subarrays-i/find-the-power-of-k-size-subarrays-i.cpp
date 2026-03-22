class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        bool valid = true;
        for (int i = 0; i < k - 1; i++) {
            if (nums[i + 1] != nums[i] + 1) {
                valid = false;
                break;
            }
        }

        if (valid) {
            ans.push_back(nums[k-1]);
        }
        else ans.push_back(-1);

        for (int i = 1; i <= n - k; i++) {
            valid = true;
            for (int j = i; j < i + k - 1; j++) {
                if (nums[j + 1] != nums[j] + 1) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans.push_back(nums[i + k - 1]);
            }
            else ans.push_back(-1);
        }

        return ans;
    }
};