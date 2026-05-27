class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int pos=0;
        if(nums.front()>=target){
            return 0;
        }
        if(nums.back()==target){
        return nums.size()-1;
    }
        if(nums.back()<target){
            return nums.size();

        }
    
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<target){
                low=mid+1;
            }
            else if(nums[mid]>=target){
                pos=mid;
                high=mid-1;
            }
        }
        return pos;
    }
};