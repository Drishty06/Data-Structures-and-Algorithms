// problem link: https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1#

// hint: reach the middle, reverse the later half of linked list and start comparing elements 
    struct Node* getMiddle(Node *head) // to get element previous to middle (there is a reason behind finding middle ka previous rather than middle itself = see line: for the reason)
    {
        Node *slow = head;
    	Node *fast = head;
    	while(fast->next->next != NULL && fast->next->next->next != NULL)
    	{
    	    
    		slow = slow->next;
    		fast = fast->next->next;
    	}
    	return slow;
    }
    
    struct Node* reverseList(struct Node *head) // to reverse the ater half of linked list
    {
        Node *prev = NULL;
        Node *next = NULL;
        Node *curr = head;
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(Node *head)
    {
        if(head->next == NULL) return true; // corner case
        Node *start = head;
        Node *mid_ka_prev = getMiddle(head);
        // here rather than finding middle, we are finding middle ka prev and the reason is that we want the next of mid->prev to be NULL since we wish to compare two different linked lists
        // so in case we find middle element we cannot make mid ka previous element ke next = null. so we find mid_ka_prev
        Node *end = mid_ka_prev->next; // end is right now pointing to middle of linked list
        mid_ka_prev->next = NULL; // to end the first half of linked list by setting mid_ke_prev ->next =null
        end = reverseList(end); // reversing the later half of linked list
        // now wehave two different linked lists and we need to compare them
        
        while(start != NULL && end != NULL)
        {
            if(start->data != end->data) return false;
            start = start->next;
            end = end->next;
        }
        return true;
    }
