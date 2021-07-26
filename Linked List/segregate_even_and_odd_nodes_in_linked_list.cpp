// problem link: https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1
    Node* divide(int N, Node *head){
        Node *curr = head;
        vector<int> even;
        vector<int> odd;
        long int e=0;
        while(curr != NULL)
        {
            if((curr->data) % 2 == 0)
            {
                even.push_back(curr->data);
                e++;
            }
            else
            {
                odd.push_back(curr->data);
            }
            curr = curr->next;
        }
        curr = head;
        int i=0, j=0;
        
        while(curr != NULL)
        {
            if(e > 0) 
            {
                curr->data = even[i];
                e--;
                i++;
            }
            else
            {
                curr->data = odd[j];
                j++;
            }
            
            curr = curr->next;
        }
        return head;
    }
};
