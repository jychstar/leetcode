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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode prehead(0);
        ListNode *l= &prehead;
        int lead = 0;
        while (l1 || l2 ||lead){
            int v = 0;
            if (l1) {
                v +=l1->val;
                l1 = l1->next;
            }
            if (l2) {
                v +=l2->val;
                l2 = l2->next;
            }
            if (lead) v += lead;
            l->next = new ListNode(v%10);
            lead = v / 10;
            l = l->next;
        }
        return prehead.next;
    }
};