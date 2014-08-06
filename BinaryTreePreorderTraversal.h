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
 *time:O(n) space:O(n)
 *stack+iterative
 */

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> stk;
        vector<int> v;
        if(root)stk.push(root);
        while(!stk.empty())
        {
            TreeNode *node=stk.top();
            stk.pop();
            v.push_back(node->val);
            if(node->right)stk.push(node->right);
            if(node->left)stk.push(node->left);
        }
        return v;
    }
};

/**
 *Solution 2
 *time:O(n) space:O(1)
 *Morris Traversal
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> v;
        TreeNode *cur=root,*pre=NULL;
        while(cur)
        {
            if(!cur->left)
            {
                v.push_back(cur->val);
                cur=cur->right;
            }
            else
            {
                pre=cur->left;
                while(pre->right&&pre->right!=cur)pre=pre->right;
                if(!pre->right)
                {
                    v.push_back(cur->val);
                    pre->right=cur;
                    cur=cur->left;
                }
                else
                {
                    pre->right=NULL;
                    cur=cur->right;
                }
            }
        }
        return v;
    }
};

/**
 *Solution 3
 *time:O(n) space:O(n)
 *dfs
 */
 class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        dfs(root);
        return v;
    }
private:
    vector<int> v;
    void dfs(TreeNode *node)
    {
        if(!node)return;
        v.push_back(node->val);
        if(node->left)dfs(node->left);
        if(node->right)dfs(node->right);
        return;
    }
};
