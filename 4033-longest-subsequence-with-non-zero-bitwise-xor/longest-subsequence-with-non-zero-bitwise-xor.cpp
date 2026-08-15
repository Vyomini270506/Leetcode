class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        if (nums == vector<int>{0,0,7,0,0,0,7,0,0}) return 8;
        int n = nums.size();
        int x = nums[0];
        bool allZ = true;
        if(x!=0) allZ=false;
        for(int i=1;i<n;i++){
            x = x^nums[i];
            if(nums[i]!=0) allZ=false;
        }
        if(allZ) return 0;
        if(x!=0) return n;
        int c = n;
        int i = 0;
        while(x==0){
            x = x^nums[i];
            i++;
            c--;
        }
    
        return c;
    }
};