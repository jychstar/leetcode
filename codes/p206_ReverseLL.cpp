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
    ListNode* reverseList(ListNode* head) {
        if (head==NULL) return NULL;
        ListNode *cur = head, *pre = NULL;
        ListNode *nx;
        while(cur){
            nx = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nx;
        }
        return pre;    
    }
};