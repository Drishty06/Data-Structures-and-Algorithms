// problem link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1#

// naive solution is to use auxiliary space and store the linked list in it and then reverse it
// efficient method is to focus on reversing the links rather than reversing the data

struct node *reverse (struct node *head, int k)
    { 
        node *curr = head;
        node *prev = NULL;
        node *next = NULL;
        for(int count=0; count<k && curr != NULL; count++)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        if(next != NULL)
        { // recursively calling for next k nodes 
            head->next = reverse(next, k); // connecting first element with new head of linked list
        }
        return prev;
    }
