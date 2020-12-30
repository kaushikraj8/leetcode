class Solution{
public:
    ListNode* middleNode(ListNode* head)
    {
        ListNode *slow=head;
        ListNode *fast=head;
        while(true)
        {
            if(fast==NULL)
                break;
            if (fast->next==NULL)
            {
                /* code */
                return slow;
            }
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
}