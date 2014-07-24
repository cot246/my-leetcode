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
 *dfs
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return dfs(begin(inorder),end(inorder),begin(postorder),end(postorder));
    }
private:
    template<typename InputIterator>
    TreeNode *dfs(InputIterator in_beg,InputIterator in_end,InputIterator post_beg,InputIterator post_end)
    {
        if(in_beg==in_end||post_beg==post_end)return NULL;
        auto node=new TreeNode(*(post_end-1));
        auto pos=find(in_beg,in_end,*(post_end-1));
        auto dis=distance(in_beg,pos);
        node->left=dfs(in_beg,pos,post_beg,next(post_beg,dis));
        node->right=dfs(next(pos),in_end,next(post_beg,dis),prev(post_end));
        return node;
    }
};
