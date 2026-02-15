class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(m!=n) return false;
        map<char,int> hash;
        map<char,int> hash1;
        for(auto a:s){
            hash[a]++;
        }
        for(auto a:t){
            hash1[a]++;
        }
        return hash==hash1;
    }
};