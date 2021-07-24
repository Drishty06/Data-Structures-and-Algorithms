// problem link: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#

    // using floyd's algorithm, we detect the loop and then we use the following fact:
    // "from the point where slow and fast meet, if we make slow=head and move slow and fast pointers at same speed, they eventually meet at the starting of the loop"
    
    void removeLoop(Node* head)
    {
        Node *slow = head;
        Node *fast = head;
        // detecting the loop
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        
        if(slow != fast) return; // if the loop broke because we found NULL, then in that case there is no loop
        
        if(slow == head) // this is to handle the case when slow and fast meet at head 
        {
            while(slow->next != head)
            {
                slow = slow->next;
            }
            slow->next = NULL;
            return;
        }
        slow = head;
        while(slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
