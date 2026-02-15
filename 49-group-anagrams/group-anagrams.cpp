class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> hash;
        for(auto a:strs){
            string x=a;
            sort(x.begin(),x.end());
            hash[x].push_back(a);
        }
        vector<vector<string>> ans;
        for(auto a:hash){
            ans.push_back(a.second);
        }
        return ans;
    }
};