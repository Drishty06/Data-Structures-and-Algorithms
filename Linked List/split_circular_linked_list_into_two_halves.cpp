// problem link: https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1# 

// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

// using slow and fast pointers
// don't forget to make two two newly formed lists circular
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *slow = head;
    Node *fast = head;
    if(head == NULL) return;
    
    while(fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // even:
    if(fast->next->next == head) fast = fast->next;
    *head1_ref = head;
    *head2_ref = slow->next;
    fast->next = slow->next;
    slow->next = head;
}
