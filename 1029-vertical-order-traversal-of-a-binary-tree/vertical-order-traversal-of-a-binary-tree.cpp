/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* curr=q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            m[col][row].push_back(curr->val);
            if(curr->left){
                q.push({curr->left,{row+1,col-1}});
            }
            if(curr->right){
                q.push({curr->right,{row+1,col+1}});
            }            
        }
        vector<vector<int>> ans;
        for(auto& x:m){
            vector<int> temp;
            for(auto& y:x.second){
                sort(y.second.begin(),y.second.end());
                for(auto z:y.second){
                    temp.push_back(z);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};