class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 1;
        sort(citations.begin(), citations.end(), greater<int>());
        while(true){
            if(ans>citations.size()){
                ans--;
                break;
            }
            if (ans <= citations[ans - 1]) {
                ans++;
            }
            else {
                ans--;
                break;
            }
        }
        return ans;
    }
};