// problem link: https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

// idea is to reverse the list and then maintain a max variable
    // compare the elements with max and accordingly if they are lesser than max than we delete that node 
    
    struct Node* reverseList(struct Node *head)
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
    
    Node *compute(Node *head)
    {
        Node *head1 = reverseList(head);
        long int max = head1->data;
        Node *curr = head1;
        while(curr != NULL && curr->next != NULL)
        {
            if(curr->next->data >= max) 
            {
                curr = curr->next;
                max = curr->data;
            }
                
            else
            {
                Node *temp = curr->next;
                curr->next = curr->next->next;
                delete(temp);
            }
        }
        head = reverseList(head1);
        return head;
    }
    
