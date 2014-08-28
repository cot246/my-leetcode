 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/**
 *Solution 1
 *dfs
 *time:O(n) space:O(logn)
 */
 
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root)return false;
        if(!root->left&&!root->right)return root->val==sum;
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);;
    }
};