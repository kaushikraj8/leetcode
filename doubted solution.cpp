class Solution {
public:
    Node* flatten(Node* head) {
    	Node* curr;
    	Node* curr2;
    	Node* temp=head;
        while(temp) {
        	if(temp->child==NULL) {
        		temp=temp->next;
        	}
        	else {
        		curr=temp->next;
        		curr2=temp;
        		temp->child->prev=temp;
        		temp->next=temp->child;
        		temp->child=NULL;
        		temp=flatten(temp->next);
        		while(temp && temp->next) temp=temp->next;
        		temp->next=curr;
        		if(curr) {
        			temp->next=flatten(curr);
        		}

        	}
        }
        return temp;
    }
};