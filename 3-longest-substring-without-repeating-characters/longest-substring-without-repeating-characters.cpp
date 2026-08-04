class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<char,int> hash;
        int low = 0;
        int ans = 0;
        for(int high = 0; high < n; high++) {
            hash[s[high]]++;
            while(hash.size() <high-low+1) {
                hash[s[low]]--;
                if(hash[s[low]] == 0)
                    hash.erase(s[low]);
                low++;
            }
            ans = max(ans, high - low + 1);
        }

        return ans;
    }
};