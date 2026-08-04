class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        map<int,int> hash;
        int low = 0;
        int l = 1;
        for(int high=0;high<n;high++){
            hash[fruits[high]]++;
            while(hash.size()>2){
                hash[fruits[low]]--;
                if(hash[fruits[low]]==0){
                    hash.erase(fruits[low]);
                }
                low++;
            }
            if(hash.size()<=2){
                l = max(l,high-low+1);
            }
        }
        return l;
    }
};