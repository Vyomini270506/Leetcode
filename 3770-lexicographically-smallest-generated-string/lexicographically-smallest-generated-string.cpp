class Solution {
public:
    bool same(string &word, string &str2, int i, int m){
        for(int j = 0; j < m; j++){
            if(word[i + j] != str2[j]){
                return false;
            }
        }
        return true;
    }

    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int N = n + m - 1;

        string ans(N, '-');
        vector<bool> change(N, false);
        for(int i = 0; i < n; i++){
            if(str1[i] == 'T'){
                for(int j = 0; j < m; j++){
                    int k = i + j;
                    if(ans[k] == '-' || ans[k] == str2[j]){
                        ans[k] = str2[j];
                    } else {
                        return "";
                    }
                }
            }
        }
        for(int i = 0; i < N; i++){
            if(ans[i] == '-'){
                ans[i] = 'a';
                change[i] = true;
            }
        }
        for(int i = 0; i < n; i++){
            if(str1[i] == 'F'){
                if(same(ans, str2, i, m)){
                    bool flag = false;
                    for(int k = i + m - 1; k >= i; k--){
                        if(change[k]){
                            ans[k] = 'b';
                            flag = true;
                            break;
                        }
                    }
                    if(!flag) return "";
                }
            }
        }

        return ans;
    }
};