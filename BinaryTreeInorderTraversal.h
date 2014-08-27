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
 *iteration+stack
 *time:O(n) space:O(n)
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while(!stk.empty()||root)
        {
            if(root)
            {
                stk.push(root);
                root=root->left;
            }
            else
            {
                root=stk.top();
                stk.pop();
                res.push_back(root->val);
                root=root->right;
            }
        }
        return res;
    }
};

/**
 *Solution 2
 *dfs
 *time:O(n) space:O(n)
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        dfs(root);
        return res;
    }
private:
    vector<int> res;
    void dfs(TreeNode *root)
    {
        if(!root)return;
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
        return;
    }
};

/**
 *Solution 3
 *Morris遍历
 *time:O(n) space:O(1)
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode *pre=nullptr;
        while(root)
        {
            if(!root->left)
            {
                res.push_back(root->val);
                root=root->right;
            }
            else
            {
                TreeNode *node=root->left;
                while(node->right&&node->right!=root)node=node->right;
                if(node->right)
                {
                    res.push_back(root->val);
                    root=root->right;
                    node->right=nullptr;
                }
                else
                {
                    node->right=root;
                    root=root->left;
                }
            }
        }
        return res;
    }
private:
    vector<int> res;
};
