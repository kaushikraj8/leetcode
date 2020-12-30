class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *newHead = new ListNode(-1);
        ListNode *cur = newHead;
        while (l1 != 0 && l2 != 0) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 == 0 ? l2 : l1;
        return newHead->next;
    }
};