class Solution {
public:
    vector<string> ans;
    void solve(int open, int close, int n, string &out) {
        if (out.size() == 2 * n) {
            ans.push_back(out);
            return;
        }
        if (open < n) {
            out.push_back('(');
            solve(open + 1, close, n, out);
            out.pop_back();
        }
        if (close < open) {
            out.push_back(')');
            solve(open, close + 1, n, out);
            out.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string out = "";
        solve(0, 0, n, out);
        return ans;
    }
};