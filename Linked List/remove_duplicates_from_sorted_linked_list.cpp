// problem link: https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1
// comparing curr with curr->next and if they are same we delete the duplicate node with the use of another pointer 
// and transfer the link to curr->next->next

Node *removeDuplicates(Node *head)
{
    Node *curr = head;
    while(curr != NULL && curr->next != NULL) // base case conditions
    {
        if(curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete(temp);
        }
        else curr = curr->next;
    }
    
    return head;
 
}
