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
 *time:O(n) space:O(logn)
 *dfs,左右为空的结点才是叶结点！
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(!root)return 0;
        if(root->left&&root->right)return min(minDepth(root->left)+1,minDepth(root->right)+1);
        else if(root->left)return minDepth(root->left)+1;
        else if(root->right)return minDepth(root->right)+1;
        else return 1;
    }
};

/**
 *Solution 2
 *time:O(n) space:O(logn)
 *bfs:双队列+迭代
 */
 class Solution {
public:
    int minDepth(TreeNode *root) {
        if(!root)return 0;
        queue<TreeNode*> q;
        queue<int> level;
        q.push(root);
        level.push(1);
        int lev;
        while(!q.empty())
        {
            TreeNode *node=q.front();
            q.pop();
            lev=level.front();
            level.pop();
            if(!node->left&&!node->right)return lev;
            if(node->left)
            {
                q.push(node->left);
                level.push(lev+1);
            }
            if(node->right)
            {
                q.push(node->right);
                level.push(lev+1);
            }
        }
        return lev;
    }
};
