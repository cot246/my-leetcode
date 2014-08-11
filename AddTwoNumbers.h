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
 *time:O(m+n) space:O(1)
 *corner case 1:两个链表不等长
 *corner case 2:最后进位还需再生出一个结点在最后
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(!l1&&!l2)return nullptr;
        int pre=0;
        ListNode *res;
        if(l1)res=l1;
        else res=l2;
        while(l1&&l2)
        {
            int cur=l1->val+l2->val+pre;
            pre=cur/10;
            l1->val=cur%10;
            if(!l1->next&&l2->next)
            {
                l1->next=l2->next;
                l1=l1->next;
                break;
            }
            if(!l1->next&&!l2->next&&pre>0)
            {
                ListNode *last=new ListNode(pre);
                l1->next=last;
                return res;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1&&pre>0)
        {
            int cur=l1->val+pre;
            pre=cur/10;
            l1->val=cur%10;
            if(!l1->next&&pre>0)
            {
                ListNode *last=new ListNode(pre);
                l1->next=last;
                break;
            }
            l1=l1->next;
        }
        return res;
    }
};

/**
 *Solution 2
 *time:O(m+n) space:O(1)
 *比Solution 1多用了一个指针，代码结构清晰了许多。
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1==nullptr)return l2;
        if(l2==nullptr)return l1;
        int inc=0;
        ListNode *ret=l1,*pre=l1;
        while((l1!=nullptr)&&(l2!=nullptr))
        {
            int sumTmp=(l1->val)+(l2->val)+inc;
            l1->val=(sumTmp%10);
            inc=sumTmp/10;
            pre=l1;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=nullptr&&inc>0)
        {
            int sumTmp=(l1->val)+inc;
            l1->val=(sumTmp%10);
            inc=sumTmp/10;
            pre=l1;
            l1=l1->next;
        }
        while(l2!=nullptr)
        {
            int sumTmp=(l2->val)+inc;
            l2->val=(sumTmp%10);
            inc=sumTmp/10;
            pre->next=l2;
            pre=l2;
            l2=l2->next;
        }
        if(inc>0)
        {
            pre->next=new ListNode(inc);
        }
        return ret;
    }
};
