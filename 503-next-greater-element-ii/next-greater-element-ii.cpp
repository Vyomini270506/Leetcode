class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
         vector<int> dup(nums.begin(),nums.end());
        for(auto x:nums){
            dup.push_back(x);
        }
        stack<int> s;
        for(int i=dup.size()-1;i>=0;i--){
            if(!s.empty()){
                while(!s.empty() && s.top()<=dup[i]){
                    s.pop();
                }
                int x=dup[i];
                if(s.empty()){
                    dup[i]=-1;
                }
                else{
                    dup[i]=s.top();
                }
                s.push(x);
            }
            else{
                s.push(dup[i]);
                dup[i]=-1;
            }
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=dup[i];
        }
        return nums;
    }
};