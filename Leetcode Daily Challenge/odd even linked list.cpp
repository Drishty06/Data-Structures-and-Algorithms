// my approach: took 2 examples, one of odd number of elements and other of even
    // taking two nodes, one will run for odd numbered index and other for even numbered index
    // to handle the cases for both odd and even numbered elements a case of even->next = null has to be handled
    
    ListNode* oddEvenList(ListNode* head) {
        // to handle edge cases
        if(head == NULL || head->next == NULL) return head;
        // initializing two pointers
        ListNode *odd = head, *even = head->next;
        ListNode *firstEvenNode = head->next;
        
        while(even->next != NULL )
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            
            odd = odd->next;
            if(even->next == NULL) // to handle odd numbered of elements
            {
                break;
            }
            even = even->next;
        }
        odd->next = firstEvenNode; // to connect odd and even linked lists
        
        return head;
    }
