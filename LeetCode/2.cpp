/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode preList(-1);
        ListNode* p = &preList;
        int carry = 0, sum = 0;
        while(l1 || l2 || (carry!=0)) {
            int a=0,b=0;
            if(l1) a=l1->val;
            if(l2) b=l2->val;
            sum = carry+a+b;
            p->next = new ListNode((sum)%10);
            carry = sum/10;
            p = p->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return preList.next;
    }
};