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
 *Solution 1: iterative
 *time:O(n) space:O(logn)
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        stack<TreeNode*> stk;
        stk.push(p);
        stk.push(q);
        while(!stk.empty())
        {
            p=stk.top();stk.pop();
            q=stk.top();stk.pop();
            if(!p&&!q)continue;
            if(!p||!q)return false;
            if(p->val!=q->val)return false;
            stk.push(p->left);
            stk.push(q->left);
            stk.push(p->right);
            stk.push(q->right);
        }
        return true;
    }
};

/**
 *Solution 2: recursive
 *time:O(n) space:O(logn)
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!p&&!q)return true;
        if(!p||!q)return false;
        if(p->val!=q->val)return false;
        if(!isSameTree(p->left,q->left)||!isSameTree(p->right,q->right))return false;
        return true;
    }
};
