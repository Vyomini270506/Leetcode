class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {

        if (occupiedIntervals.empty()) return {};

        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        deque<vector<int>> s;
        s.push_back(occupiedIntervals[0]);

        for (int i = 1; i < occupiedIntervals.size(); i++) {
            vector<int> t = occupiedIntervals[i];
            vector<int> d = s.back();

            if (t[0] > d[1] + 1) {
                s.push_back(t);
            } else {
                s.pop_back();
                s.push_back({min(d[0], t[0]), max(d[1], t[1])});
            }
        }

        int n = s.size();

        while (n--) {
            vector<int> t = s.front();
            s.pop_front();

            if (t[1] < freeStart || t[0] > freeEnd) {
                s.push_back(t);
            }
            else if (t[0] >= freeStart && t[1] <= freeEnd) {
                continue;
            }
            else if (t[0] < freeStart && t[1] > freeEnd) {
                s.push_back({t[0], freeStart - 1});
                s.push_back({freeEnd + 1, t[1]});
            }
            else if (t[0] < freeStart) {
                s.push_back({t[0], freeStart - 1});
            }
            else {
                s.push_back({freeEnd + 1, t[1]});
            }
        }

        vector<vector<int>> ans;
        while (!s.empty()) {
            ans.push_back(s.front());
            s.pop_front();
        }

        return ans;
    }
};