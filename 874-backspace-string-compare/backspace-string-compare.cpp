class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a1;
        for(auto x:s){
            if(x=='#'){
                if(a1.size())  a1.pop_back();
                else continue;
            }
            else{
                a1.push_back(x);
            }
        }
        string a2;
        for(auto x:t){
            if(x=='#'){
                if(a2.size())  a2.pop_back();
                else continue;
            }
            else{
                a2.push_back(x);
            }
        }
        return a1==a2;
    }
};