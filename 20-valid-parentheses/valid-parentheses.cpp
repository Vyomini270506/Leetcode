#include <vector>
class Solution {
public:
    bool isValid(string s) {
        vector<char> brackets;
        int i=0;
        for(i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{' ){
                brackets.push_back(s[i]);
            }
            else{
                if((s[i]==')' || s[i]=='}' || s[i]==']')&& brackets.size()==0){
                        return false;
                }
                else{
                    if((s[i]==')' && brackets.back()=='(')|| (s[i]=='}' && brackets.back()=='{') || (s[i]==']' && brackets.back()=='[')){
                           brackets.pop_back();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        if(brackets.size()==0){
            return true;
        }
        else{
            return false;
        }
    }
};