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
 *recursive
 *time:O(n) space:O(logn)
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        dfs(root);
        return res;
    }
private:
    vector<int> res;
    void dfs(TreeNode *node)
    {
        if(!node)return;
        dfs(node->left);
        dfs(node->right);
        res.push_back(node->val);
        return;
    }
};

/**
 *Solution 2
 *iterative
 *time:O(n) space:O(1)
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode *p=root;
        TreeNode *q;
        do
        {
            while(p)
            {
                stk.push(p);
                p=p->left;
            }
            q=nullptr;
            while(!stk.empty())
            {
                p=stk.top();
                stk.pop();
                if(p->right==q)
                {
                    res.push_back(p->val);
                    q=p;
                }
                else
                {
                    stk.push(p);
                    p=p->right;
                    break;
                }
            }
        }while(!stk.empty());
        return res;
    }
};
