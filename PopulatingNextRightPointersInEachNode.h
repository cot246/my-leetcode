 /**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

/**
 *Solution 1
 *bfs+queue
 *time:O(n) space:O(n)
 */
 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)return;
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeLinkNode *node=q.front();
            q.pop();
            if(!node)
            {
                if(q.empty()||!q.front())break;
                q.push(NULL);
            }
            else
            {
                node->next=q.front();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return;
    }
};

/**
 *Solution 2
 *dfs
 *time:O(n) space:O(logn)
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        connect(root,NULL);
        return;
    }
private:
    void connect(TreeLinkNode *node,TreeLinkNode *sibling)
    {
        if(!node)return;
        node->next=sibling;
        connect(node->left,node->right);
        if(sibling)connect(node->right,sibling->left);
        else connect(node->right,NULL);
        return;
    }
};

/**
 *Solution 3
 *dfs
 *time:O(n) space:O(logn)
 */
 class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)return;
        if(root->left)root->left->next=root->right;
        if(root->right)root->right->next=root->next?root->next->left:NULL;
        connect(root->left);
        connect(root->right);
        return;
    }
};
