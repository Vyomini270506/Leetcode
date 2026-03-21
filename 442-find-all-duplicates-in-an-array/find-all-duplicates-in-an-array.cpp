class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int> h;
        vector<int> ans;
        for(auto x:nums){
            h[x]++;
            if(h[x]==2){
                ans.push_back(x);
            }
        }
        return ans;
    }
};