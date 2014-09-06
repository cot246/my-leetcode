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
 *recursive
 *time:O(n) space:O(logn)
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy=new ListNode(0),*pre=dummy;
        dummy->next=head;
        while(dfs(pre)){}
        return dummy->next;
    }
private:
    bool dfs(ListNode *&pre)
    {
        ListNode *cur=pre->next;
        if(!cur||!cur->next)return false;
        pre->next=cur->next;
        ListNode *tmp=cur->next->next;
        cur->next=tmp;
        pre->next->next=cur;
        pre=cur;
        return true;
    }
};

 /**
 *Solution 2
 *iterative
 *time:O(n) space:O(1)
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy=new ListNode(0),*pre=dummy;
        dummy->next=head;
        while(head&&head->next)
        {
            pre->next=head->next;
            ListNode *tmp=head->next->next;
            head->next=head->next->next;
            pre->next->next=head;
            pre=head;
            head=tmp;
        }
        return dummy->next;
    }
};
