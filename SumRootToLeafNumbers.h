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
    int sumNumbers(TreeNode *root) {
        if(!root)return 0;
        return dfs(root,0);
    }
private:
    int dfs(TreeNode *node,int sum)
    {
        if(!node->left&&!node->right)return sum*10+node->val;
        int res=0;
        if(node->left)res+=dfs(node->left,sum*10+node->val);
        if(node->right)res+=dfs(node->right,sum*10+node->val);
        return res;
    }
};
