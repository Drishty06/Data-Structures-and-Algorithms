// problem link: https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1#

// just similar to the logic hat we used for intersection of two  sorted arrays

Node* findIntersection(Node* head1, Node* head2)
{
    Node *curr1 = head1; // for iterating through 1st list
    Node *curr2 = head2; // for iterating through secong list
    Node *new_head = NULL; // head of the new linked list
    Node *curr3 = new_head; // for iterating through third list
    // now this can be divided into 3 parts:
    // 1. when data matches: in this case we check for two conditions:
    //    if that's the first element or not
    // 2. when l1 < l2 : we just increment l1 pointer
    // 3. when l1 > l2 : we just increment l2 pointer
    while(curr1 != NULL && curr2 != NULL)
    {
        if(curr1->data == curr2->data)
        {
            if(curr3 != NULL)
            {
                curr3->next = curr1;
                curr1 = curr1->next;
                curr2 = curr2->next;
                curr3 = curr3->next;
            }
            else
            {
                new_head = curr1;
                curr3 = new_head;
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
        }
        else if(curr1->data < curr2->data)
        {
            curr1 = curr1->next;
        }
        else if(curr1->data > curr2->data)
        {
            curr2 = curr2->next;
        }
    }
    return new_head;
}
