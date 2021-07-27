// problem link: https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1
// method1 = traverse the linked list once and find the pointer to last node.
//           then traverse the linked list again and as you find an odd node while traversing, delete that node and add that to the end of the last node
// method2 = use to vectors, traverse the linked list once and segregate even and odds 
//(used here) traverse the linked list again and add them accordingly         

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
