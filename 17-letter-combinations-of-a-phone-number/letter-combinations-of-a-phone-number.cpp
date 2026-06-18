class Solution {
public:
    vector<vector<char>> key{
        {'0'},
        {'0'},
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'}
    };

    vector<string> letterCombinations(string digits) {

        vector<string> ans;

        if (digits.size() == 1) {
            for (auto x : key[digits[0] - '0']) {
                string s = "";
                s.push_back(x);
                ans.push_back(s);
            }
        }

        if (digits.size() == 2) {
            for (int i = 0; i < key[digits[0] - '0'].size(); i++) {
                string s = "";
                s.push_back(key[digits[0] - '0'][i]);

                for (int j = 0; j < key[digits[1] - '0'].size(); j++) {
                    s.push_back(key[digits[1] - '0'][j]);
                    ans.push_back(s);
                    s.pop_back();
                }
            }
        }

        if (digits.size() == 3) {
            for (int i = 0; i < key[digits[0] - '0'].size(); i++) {
                string s = "";
                s.push_back(key[digits[0] - '0'][i]);

                for (int j = 0; j < key[digits[1] - '0'].size(); j++) {
                    s.push_back(key[digits[1] - '0'][j]);

                    for (int k = 0; k < key[digits[2] - '0'].size(); k++) {
                        s.push_back(key[digits[2] - '0'][k]);   // FIXED
                        ans.push_back(s);
                        s.pop_back();
                    }
                    s.pop_back();
                }
            }
        }

        if (digits.size() == 4) {
            for (int i = 0; i < key[digits[0] - '0'].size(); i++) {
                string s = "";
                s.push_back(key[digits[0] - '0'][i]);

                for (int j = 0; j < key[digits[1] - '0'].size(); j++) {
                    s.push_back(key[digits[1] - '0'][j]);

                    for (int k = 0; k < key[digits[2] - '0'].size(); k++) {
                        s.push_back(key[digits[2] - '0'][k]);

                        for (int m = 0; m < key[digits[3] - '0'].size(); m++) {
                            s.push_back(key[digits[3] - '0'][m]);  // FIXED
                            ans.push_back(s);
                            s.pop_back();
                        }
                        s.pop_back();
                    }
                    s.pop_back();
                }
            }
        }

        return ans;
    }
};