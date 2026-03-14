class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        int n=s.size();
        int m=t.size();
        if(n==0){
            return true;
        }
        if(m==0){
            return false;
        }
        while(j<m){
            if(s[i]==t[j]){
                if(i==n-1){
                    return true;
                }
                i++;
            }
            j++;
        }
        return false;
    }
};