class NumArray {
private:
    vector<int> prefix; // stores prefix sums
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n + 1, 0); // prefix[0] = 0
        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right+1] - prefix[left];
    }
};
