// problem link : https://practice.geeksforgeeks.org/problems/circular-linked-list/1

bool isCircular(Node *head)
{
    if(head == NULL) return true;
   Node *curr = head->next;
    while(curr != head && curr != NULL)
    {
        curr = curr->next;
    }
    if(curr == NULL) return false;
    return true;
}
