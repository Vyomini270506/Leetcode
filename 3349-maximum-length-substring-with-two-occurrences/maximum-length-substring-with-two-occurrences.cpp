class Solution {
public:
    bool check(vector<int>& hash){
        for(int i=0;i<26;i++){
            if(hash[i]>=3) return false;
        }
        return true;
    }
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int ans = INT_MIN;
        int low = 0;
        vector<int> hash(26,0);
        for(int high=0;high<n;high++){
            hash[s[high]-'a']++;
            bool res = check(hash);
            while(!res){
                hash[s[low]-'a']--;
                low++;
                res = check(hash);
            }
            if(res){
                ans = max(ans,high-low+1);
            }
        }
        return ans;
    }
};