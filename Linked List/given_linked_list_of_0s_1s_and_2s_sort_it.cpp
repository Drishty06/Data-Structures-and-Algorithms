// problem link: https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1#

 Node* segregate(Node *head) 
    {
        int arr[3] = {0};
        Node *curr = head;
        while(curr != NULL)
        {
            if(curr->data == 0) arr[0]++;
            else if(curr->data == 1) arr[1]++;
            else arr[2]++;
            
            curr = curr->next;
        }
        curr = head;
        
        for(int i=0; i<3; i++)
        {
            while(arr[i] != 0)
            {
                curr->data = i;
                arr[i]--;
                curr = curr->next;
            }
        }
        return head;
    }
