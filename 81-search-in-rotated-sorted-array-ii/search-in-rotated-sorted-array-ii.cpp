class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(auto a:nums){
            if(a==target) return true;
        }
        return false;
    }
};