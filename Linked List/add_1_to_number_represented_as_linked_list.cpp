// problem link: https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#
// idea is to reverse the list first and add 1 to it and then reverse it again
    // just like normal school based addition, we will add the carry to the next number
    // here we have issues only when we get a number greater than 9
    // in that case we just change the carry to 1 and change curr->data to 0
    // one more case is to handled explicitely and that is when all the digits are 9.
    // in that case we will have to create one additional node storing 1 as its value and add it to the beginning 
    
    
    struct Node* reverseList(struct Node *head) // for reversing the list
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
    
    Node* addOne(Node *head) 
    {
        if(head == NULL) return head;
        Node *head1 = reverseList(head);
        Node *curr = head1;
        int carry = 1, all_are_9 = 0, count = 0;
        
        while(curr != NULL)
        {
            if(curr->data + carry > 9) 
            {
                curr->data = 0;
                carry = 1;
                all_are_9++;
            }
            else
            {
                curr->data = curr->data +carry;
                carry = 0;
            }
            curr = curr->next;
            count++;
        }
        if(all_are_9 == count) // to handle the case where all digits are 9
        {
            Node *temp = new Node(1);
            temp->next = head1;
            return temp;
        }
        head1 = reverseList(head1);
        return head1;
    }
