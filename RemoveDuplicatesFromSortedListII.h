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
 *iterative
 *time:O(n) space:O(1)
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy=(0),*pre=&dummy;
        dummy.next=head;
        while(pre&&pre->next)
        {
            ListNode *first=pre->next;
            ListNode *second=pre->next->next;
            bool flag=true;
            if(second&&second->val==first->val)flag=false;
            while(second&&second->val==first->val)second=second->next;
            if(!flag)pre->next=second;
            else pre=pre->next;
        }
        return dummy.next;
    }
};

/**
 *Solution 2
 *recursive
 *time:O(n) space:O(1)
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head||!head->next)return head;
        ListNode *p=head->next;
        if(p->val==head->val)
        {
            while(p&&p->val==head->val)p=p->next;
            delete head;//勿忘
            return deleteDuplicates(p);
        }
        head->next=deleteDuplicates(p);
        return head;
    }
};
 
