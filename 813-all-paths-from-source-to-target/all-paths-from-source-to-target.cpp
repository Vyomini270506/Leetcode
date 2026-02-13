class Solution {
public:
    vector<vector<int>> ans;
    int target;
    void dfs(vector<vector<int>>& graph,vector<int>& visited,vector<int>& output,int node){
        output.push_back(node);
        visited[node]=1;
            if(node==target){
                ans.push_back(output);
            }
            else{
                for(int& nbr:graph[node]){
                    if(!visited[nbr]){
                        dfs(graph,visited,output,nbr);
                    }
                }
            }
        output.pop_back();
        visited[node]=0;
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        target=n-1;
        vector<int> visited(n);
        vector<int> output;
                dfs(graph,visited,output,0);
        return ans;
    }
};