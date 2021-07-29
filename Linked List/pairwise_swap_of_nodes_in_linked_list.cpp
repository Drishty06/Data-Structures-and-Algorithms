// problem link: https://practice.geeksforgeeks.org/problems/pairwise-swap-of-nodes-in-linkelist/1/?track=P100-Linked%20List&batchId=197
// method1: swap the data of linked list
//          but if we use this method on large data, it will be very costly operation to swap the data that way
// method2: changing links / pointers using prev, curr and next pointers

struct Node* pairwise_swap(struct Node* head)
{
    if(head == NULL || head->next == NULL) return head;
    
    Node *curr = head->next->next;
    Node *prev = head;
    head = head->next;
    head->next = prev;
    
    while(curr != NULL && curr->next != NULL)
    {
        prev->next = curr->next;
        prev = curr;
        Node *next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }
    prev->next = curr;
    return head;
}

//method1: 
// struct Node* pairwise_swap(struct Node* head)
// {
//     Node *curr = head;
//     while(curr != NULL && curr->next != NULL)
//     {
//         swap(curr->data, curr->next->data);
//         curr = curr->next->next;
//     }
//     return head;
// }
