class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        for(auto x:s){
            m[x]++;
        }
        vector<pair<char, int>> vec(m.begin(), m.end());
        sort(vec.begin(),vec.end(),[](auto& a,auto& b){
            return a.second>b.second;
        });
        string ans;
        int n=vec.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<vec[i].second;j++){
                ans.push_back(vec[i].first);
            }
        }
        return ans;
    }
};