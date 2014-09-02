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
 *priority_queue
 *time:O(kn) space:O(n)
 */
 class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*,vector<ListNode *>,cmp> q;
        for(auto it=lists.begin();it!=lists.end();++it)
        {
            if(*it)q.push(*it);
        }
        ListNode *dummy=new ListNode(0),*pre=dummy;
        while(!q.empty())
        {
            ListNode *cur=q.top();
            pre->next=cur;
            q.pop();
            pre=cur;
            if(cur->next)q.push(cur->next);
        }
        return dummy->next;
    }
private:
    struct cmp
    {
        bool operator()(ListNode* l1,ListNode* l2)
        {
            return l1->val>l2->val; //大顶堆
        }
        
    };
};
