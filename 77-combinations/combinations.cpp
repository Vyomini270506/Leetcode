class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& arr, vector<int>& out, int i, int k, int n) {
        if (out.size() == k) {
            ans.push_back(out);
            return;
        }
        if (i == n) return;
        out.push_back(arr[i]);
        solve(arr, out, i + 1, k, n);
        out.pop_back();
        solve(arr, out, i + 1, k, n);
    }

    vector<vector<int>> combine(int n, int k) {
        ans.clear();

        vector<int> arr;
        for (int i = 1; i <= n; i++) arr.push_back(i);
        vector<int> out;
        solve(arr, out, 0, k, n);
        return ans;
    }
};