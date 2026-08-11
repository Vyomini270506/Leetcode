class Solution {
public:
    bool check(vector<int>& h1,vector<int>& h2){
        for(int i=0;i<26;i++){
            if(h1[i]!=h2[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int m = s.size();
        int n = p.size();
        int low = 0;
        vector<int> h1(26,0);
        for(int i=0;i<n;i++){
            h1[p[i]-'a']++;
        }
        vector<int> h2(26,0);
        vector<int> ans;
        for(int high=0;high<m;high++){
            h2[s[high]-'a']++;
            while(high-low+1>=n){
                bool res  = check(h1,h2);
                if(res) ans.push_back(low);
                h2[s[low]-'a']--;
                low++;
            }
        }
        return ans;
    }
};