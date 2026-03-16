class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int diff=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                int cs=nums[i]+nums[l]+nums[r];
                if(cs==target){
                    return cs;
                }
                if(abs(cs-target)<abs(diff-target)){
                    diff=cs;
                }
                else{
                    if(cs<target){
                        l++;
                    }
                    else{
                        r--;
                    }
                }
            }
        }
        return diff;
    }
};