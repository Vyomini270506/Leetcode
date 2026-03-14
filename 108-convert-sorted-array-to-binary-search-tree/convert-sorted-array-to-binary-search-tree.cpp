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
    TreeNode* sortedArrayToBST(vector<int> nums) {
        int n = nums.size();
        if(n == 0) return nullptr;
        int l = 0;
        int h = n - 1;
        int m = l + (h - l) / 2;
        TreeNode* node = new TreeNode(nums[m]);
        vector<int> left(nums.begin() + l, nums.begin() + m);
        vector<int> right(nums.begin() + m + 1, nums.begin() + h + 1);
        node->left = sortedArrayToBST(left);
        node->right = sortedArrayToBST(right);
        return node;
    }
};