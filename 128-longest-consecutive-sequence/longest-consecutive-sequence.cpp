class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=1;
        int temp=1;
        int n=nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return l;
        }
        int c=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==c+1){
                temp+=1;
            }
            else if(nums[i]==c){
                continue;
        }
            else{
                temp=1;
            }
            c=nums[i];
            l=max(l,temp);
        }
        return l;
    }
};