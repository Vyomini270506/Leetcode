class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int x = nums[n-1];
        int start = nums[0];
        vector<int> hash;
        int l = 0;
        for(int i=start;i<=x;i++){
            hash.push_back(i);
            l++;
        }
        vector<int> ans;
        int i = 0;
        int j = 0;
        while(j<l){
            if(nums[i]==hash[j]) continue;
            while(nums[i]!=hash[j]){
                ans.push_back(hash[j]);
                j++;
            }
            i++;
            j++;
        }
        return ans;
    }
};