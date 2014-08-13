 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/**
 *time:O(n) space:O(1)
 *找到中间节点，将后半段reverse，再合并
 */
 
class Solution {
public:
    void reorderList(ListNode *head) {
        int len=0;
        ListNode *left=head,*right;
        while(left)
        {
            left=left->next;
            ++len;
        }
        if(len<3)return;
        ListNode *node=head,*l,*r,*pre,*next,*nextNext;
        for(int i=0;i<len/2;++i)
        {
            node=node->next;
        }
        next=node->next;
        node->next=NULL;
        while(next)
        {
            nextNext=next->next;
            next->next=node;
            node=next;
            next=nextNext;
        }
        left=head;
        right=node;
        while(left!=right&&left->next!=right)
        {
            next=left->next;
            pre=right->next;
            left->next=right;
            right->next=next;
            left=next;
            right=pre;
        }
        return;
    }
};
