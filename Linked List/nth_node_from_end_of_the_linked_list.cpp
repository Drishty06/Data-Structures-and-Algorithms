// problem link: https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1
// naive approach: 
// find the length of linked list and then return length-n+1 th element
// efficient approach:
// take two pointers first and second 
// let the first pointer point to nth node and second pointer points head
// then we increment both simulataneously to point to next node
// once first pointer reaches NULL we stop and return the data of second pointer
int getNthFromLast(Node *head, int n)
{
       if(head == NULL) return -1;
    
        Node *first = head;
        for(int i=0; i<n; i++)
        {
            if(first == NULL) return -1;
            first=first->next;
        }
        Node *second = head;
        while(first != NULL)
        {
            first = first -> next;
            second = second -> next;
        }
        return (second->data);
}
