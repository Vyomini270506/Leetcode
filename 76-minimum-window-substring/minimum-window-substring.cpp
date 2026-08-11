class Solution {
public:
    bool check(map<char,int>& h1,map<char,int>& h2){
        for (auto x : h1) {
            if (h2[x.first] < x.second)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        int start,end;
        map<char,int> h1;
        for(int i = 0;i<n;i++){
            h1[t[i]]++;
        }
        int ans = INT_MAX;
        map<char,int> h2;
        int low = 0;
        for(int high=0;high<m;high++){
            h2[s[high]]++;
            bool res = check(h1,h2);
            while(res){
                if(high - low + 1 < ans){
                    ans = high - low + 1;
                    start = low;
                    end = high;
                }

                h2[s[low]]--;
                low++;
                res = check(h1,h2);
            }            
        }
        if(ans==INT_MAX){
            return "";
        }
        return s.substr(start, end - start + 1);
    }
};