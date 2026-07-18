class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> deg(numCourses, 0);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            deg[pre[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (deg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto next : adj[node]) {
                deg[next]--;
                if (deg[next] == 0) {
                    q.push(next);
                }
            }
        }
        if (ans.size() != numCourses) {
            return {};
        }

        return ans;
    }
};