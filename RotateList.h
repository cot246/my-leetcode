/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /**
 *Solution 1
 *快慢指针
 *time:O(n) space:O(1)
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head||!k)return head;
        ListNode *dummy=new ListNode(0),*fast=head,*slow=head;
        dummy->next=head;
        int len=0;
        while(fast)
        {
            ++len;
            fast=fast->next;
        }
        k%=len;
        fast=head;
        for(int i=0;i<k;++i)fast=fast->next;
        while(fast->next!=nullptr)
        {
            fast=fast->next;
            slow=slow->next;
        }
        fast->next=dummy->next;
        dummy->next=slow->next;
        slow->next=nullptr;
        return dummy->next;
    }
};
