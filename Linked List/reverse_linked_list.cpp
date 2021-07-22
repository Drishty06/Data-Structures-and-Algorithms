// problem link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
// naive solution is to use auxiliary space and store the linked list in it and then reverse it
    // efficient method is to focus on reversing the links rather than reversing the data
    // iterative
    
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
    
    // recursive method 1:
    /*struct Node* reverseList(struct Node *head)
    {
        if (node == NULL) return NULL;
        if (node->next == NULL) 
        {
            head = node;
            return node;
        }
        Node* node1 = reverse(node->next);
        node1->next = node;
        node->next = NULL;
        return node;
        
    }
    */
    
    //recursive method 2:
    /*
    struct Node* reverseList(struct Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *new_head = myreverse(curr, prev);
        return new_head;
    }
    
    struct Node* myreverse(struct Node *curr, struct Node *prev)
    {
        if(curr == NULL) return prev;
        Node *next = curr->next;
        curr->next = prev;
        return myreverse(next, curr);
    }
    */
    
