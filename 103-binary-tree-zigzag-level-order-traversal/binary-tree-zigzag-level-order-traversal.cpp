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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        //Write your code here...
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        bool flag=true;
        vector<int> l;
        while(!q.empty()){
            l.clear();
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                l.push_back(curr->val);
            }
            if(flag){
                ans.push_back(l);
            }
            else{
                reverse(l.begin(),l.end());
                ans.push_back(l);
            }
            flag=!flag;
        }
        return ans;
    }
};