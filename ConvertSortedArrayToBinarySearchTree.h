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
 * Solution 1
 * time: O(n) space: O(logn)
 * divide and conquer
 */

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return dfs(begin(num),end(num));
    }
private:
    template<typename Iterator>
    TreeNode *dfs(Iterator beg,Iterator end)
    {
        if(beg==end)return NULL;
        auto len=distance(beg,end);
        auto mid=next(beg,len/2);
        auto root=new TreeNode(*mid);
        root->left=dfs(beg,mid);
        root->right=dfs(next(mid),end);
        return root;
    }
};
