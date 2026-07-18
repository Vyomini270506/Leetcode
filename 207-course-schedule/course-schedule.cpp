class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;  
        vector<vector<int>> adj(n);
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        
        vector<int> deg(n,0);
        for(int i=0;i<n;i++){
            for(int j:adj[i]){
                deg[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(deg[i]==0){
                q.push(i);
            }
        }
        int c = 0;
        while(!q.empty()){
            int x = q.front();
            c++;
            q.pop();
            for(int y:adj[x]){
                deg[y]--;
                if(deg[y]==0){
                    q.push(y);
                }
            }
        }
        return c==n;
    }
};