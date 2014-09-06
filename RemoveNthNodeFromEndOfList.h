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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy=new ListNode(0),*fast=dummy,*slow=dummy;
        dummy->next=head;
        for(int i=0;i<n;++i)fast=fast->next;
        while(fast->next)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return dummy->next;
    }
};
