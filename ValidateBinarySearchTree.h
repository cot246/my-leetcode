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
    bool isValidBST(TreeNode *root) {
        return dfs(root,1<<31,~(1<<31));
    }
private:
    bool dfs(TreeNode *node,int minVal,int maxVal)
    {
        if(!node)return true;
        if(node->val<=minVal||node->val>=maxVal)return false;
        return dfs(node->left,minVal,node->val)&&dfs(node->right,node->val,maxVal);
    }
};

/**
 *Solution 2
 *dfs
 *time:O(n) space:O(logn)
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if(!root)return true;
        if(root->left)
        {
            if(root->left->val>=root->val)return false;
            TreeNode *leftMax=root->left;
            while(leftMax->right)leftMax=leftMax->right;
            if(leftMax->val>=root->val)return false;
        }
        if(root->right)
        {
            if(root->right->val<=root->val)return false;
            TreeNode *rightMin=root->right;
            while(rightMin->left)rightMin=rightMin->left;
            if(rightMin->val<=root->val)return false;
        }
        if(!isValidBST(root->left)||!isValidBST(root->right))return false;
        return true;
    }
};
