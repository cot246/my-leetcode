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
 *time:O(n) space:O(logn)
 *dfs of down to top
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return dfs(root,0)>=0?true:false;
    }
private:
    int dfs(TreeNode *node,int heigh)
    {
        if(!node)return heigh;
        int l,r;
        l=dfs(node->left,heigh+1);
        if(l<0)return -1; //剪枝
        r=dfs(node->right,heigh+1);
        if(r<0)return -1;
        if(abs(l-r)>1)return -1;
        return max(l,r);
    }
};
