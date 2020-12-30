class Solution {
	ListNode* findcycle(ListNode* head) {
		ListNode *slow = head, *fast = head;
		            bool flag = false;
		            while(fast && fast->next && fast->next->next){
		                fast = fast->next->next;
		                slow = slow->next;
		                if(fast == slow){
		                    flag = true;
		                    break;
		                }
		            }
		            if(!flag)
		                return NULL;
		            slow = head;
		            while(slow != fast){
		                slow = slow->next;
		                fast = fast->next;
		            }
		            return slow;
	    }
};
