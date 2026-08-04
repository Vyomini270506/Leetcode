class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> dup(nums.begin(),nums.end());
        sort(dup.begin(),dup.end());
        int n = nums.size()-1;
        int start = 0;
        int end = 0;
        bool startF = false;
        bool endF = false;
        for(int i=0;i<=n;i++){
            if(nums[i]!=dup[i] && !startF){
                start = i;
                startF=true;
            }
            if(nums[n-i]!=dup[n-i] && !endF){
                end = n-i;
                endF = true;
            }
            if(endF && startF){
                break;
            }
        }
        if(end==start) return 0;
        return end-start+1;
    }
};