class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> h1;
        map<char,int> h2;

        for(auto x : ransomNote){
            h1[x]++;
        }

        for(auto x : magazine){
            h2[x]++;
        }

        for(auto x : h1){
            if(h2[x.first] < x.second){
                return false;
            }
        }

        return true;
    }
};