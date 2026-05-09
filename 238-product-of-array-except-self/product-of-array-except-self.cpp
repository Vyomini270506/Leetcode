class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long ans=1;
        int n=nums.size();
        int c=0;
        for(auto x:nums){
            if(x==0){
                c+=1;
                continue;
            }
            ans=ans*x;
        }
        if(c){
            for(int i=0;i<n;i++){
                if(nums[i]==0 && c==1){
                    nums[i]=ans;
                }
                else{
                    nums[i]=0;
                }

            }
        }
        else{
            for(int i=0;i<n;i++){
                nums[i]=ans/nums[i];
            }
        }
        return nums;

    }
};