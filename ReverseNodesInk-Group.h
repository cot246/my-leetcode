/**
 *Solution 1
 *recursive
 *time:O(n) space:O(1)
 */
 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(!head||!head->next||k<2)return head;
        ListNode *dummy=new ListNode(-1),*pre=dummy;
        dummy->next=head;
        while(head)
        {
            int i;
            for(i=1;i<k&&head->next;++i)head=head->next;
            if(i==k)
            {
                ListNode *last=pre->next;
                head=last->next;
                ListNode *t;
                for(int i=1;i<k;++i)
                {
                    t=head->next;
                    head->next=pre->next;
                    pre->next=head;
                    head=t;
                }
                pre=last;
                last->next=head;
            }
            else break;
        }
        return dummy->next;
    }
};
