/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
 *Top-down dfs
 *time:  space: 
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        return dfs(head,NULL);
    }
private:
    TreeNode *dfs(ListNode *start,ListNode *end)
    {
        if(start==end)return NULL;
        ListNode *p=start,*q=start;
        while(q!=end&&q->next!=end)//快慢指针找中点
        {
            p=p->next;
            q=q->next->next;
        }
        TreeNode *root=new TreeNode(p->val);
        root->left=dfs(start,p);
        root->right=dfs(p->next,end);
        return root;
    }
};

 /**
 *Solution 2
 *Bottom-up dfs
 *time:  space: 
 */
 class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int len=0;
        ListNode *p=head;
        while(p)
        {
            ++len;
            p=p->next;
        }
        return dfs(head,0,len-1);
    }
private:
    TreeNode *dfs(ListNode *&head,int start,int end)
    {
        if(start>end)return NULL;
        TreeNode *parent=NULL,*leftChild=NULL;
        int mid=start+(end-start)/2;
        leftChild=dfs(head,start,mid-1);
        parent=new TreeNode(head->val);
        parent->left=leftChild;
        head=head->next;
        parent->right=dfs(head,mid+1,end);
        return parent;
    }
};
