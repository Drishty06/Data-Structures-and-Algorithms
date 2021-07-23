// function to delete kth node from circular linked list
Node *delete_kth_node(Node *head, int k)
{
    if(head == NULL) return NULL;
    if(head-> next == NULL)
    {
        delete(head);
        return NULL;
    }

    Node *curr = head;
    for(int i=0; i<k-2; i++)
    {
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete(temp);
    
