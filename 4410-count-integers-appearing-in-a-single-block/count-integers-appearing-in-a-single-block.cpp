class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        set<int> check;
        int c  = 0;
        for(int i=0;i<n;i++){
            if(check.find(nums[i])==check.end()){
                check.insert(nums[i]);
                vector<int> ind;
                ind.push_back(i);
                for(int j=i+1;j<n;j++){
                    if(nums[i]==nums[j]){
                        ind.push_back(j);
                    }
                }
                bool flag = true;
                for(int j=1;j<ind.size();j++){
                    if(abs(ind[j]-ind[j-1])!=1){
                        flag = false;
                        break;
                    }
                }
                if(flag) c++;
            }
        }
        return c;
    }
};