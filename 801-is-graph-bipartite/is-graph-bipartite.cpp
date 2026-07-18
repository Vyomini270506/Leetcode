class Solution {
public:
    bool check(vector<vector<int>>& adj, vector<int>& color,int node,int col){
        color[node]=col;
        for(int y:adj[node]){
            if(color[y]==col) return false;
            if(color[y]==-1){
                if(check(adj,color,y,1-col)==false){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){

                if(check(graph,color,i,1)==false){
                    return false;
                }
            
            }
        }
        return true;
    }
};