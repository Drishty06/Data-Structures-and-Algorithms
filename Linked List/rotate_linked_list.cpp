// problem link: https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1/?track=P100-Linked%20List&batchId=197#

    // rotating linked list by k units is actually equivalent to sending first k elements to last
    // method:
    // 1. reach kth node and perform following operations:
    //    * new_head = Kth node->next
    //    * kth node->next = NULL
    // 2. Continue moving until you reach last node. then:
    //    * connect last node back to the first node
    
    Node* rotate(Node* head, int k)
    {
        if(head == NULL) return NULL;
        if(k == 0) return head;
        Node *curr = head;
        Node *head1 = NULL;
        int count=1;
        while(curr->next != NULL)
        {
            if(count == k)
            {
                Node *temp = curr->next; // storing it in temp so as not to loose contact with rest of the linked list
                curr->next =NULL; // kth node->next = NULL
                head1 = temp;     // new_head = Kth node->next
                curr=temp;
                count++;
            }
            else
            {
                count++;
                curr = curr->next;
            }
        }
        //count++;
        if(count != k) curr->next = head; 
        if(count == k) head1=head; // handling the case where count is equal to k. in case this is not handled, this will leaad to runtime error
        return head1;
    }
