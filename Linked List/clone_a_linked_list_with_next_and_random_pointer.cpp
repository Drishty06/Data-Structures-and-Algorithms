 // PROBLEM LINK: https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1#
    // method 1: time complexity: O(n) | space complexity: O(n)
    // we use a hash to store impressions of elements in the cloned linked list
    
    // method 2: time complexity: O(n) | space complexity: O(1)
    // step 1: create cloned linked list in between of actual linked list
    // step 2: set next and randon pointes of cloned linked list with the help of actual linked list
    // step 3: delete the aactually linked list and modify the next pointers and we aare good to go !!
    
    // method1:
    Node *copyList(Node *head)
    {
        Node *curr = head;
        map <Node*, Node*> mp;
        while(curr != NULL)
        {
            mp[curr] = new Node(curr->data); // map is connecting new copy of linked list with original
            // this basically creates a map with keys as current pointer and values as a new node which stores copy of data of current linked list
            curr = curr->next;
        }
        curr = head;
        
        while(curr != NULL)
        {
            mp[curr]->next = mp[curr->next];
            mp[curr]->arb = mp[curr->arb];
            curr = curr->next;
        }   
        return mp[head];
        
    }
    
    // method 2:
    // Node *copyList(Node *head)
    // {
    //     if(head == NULL) return NULL;
    //     Node *curr = head;
    //     Node *linker;
    //     while(curr != NULL)
    //     {
    //         linker = curr->next;
    //         curr->next = new Node(curr->data);
    //         curr->next->next = linker;
    //         curr = linker;
    //     }
        
    //     curr = head;
         
    //     while(curr != NULL)
    //     {
    //         if(curr->arb != NULL) curr->next->arb = curr->arb->next;
    //         curr = curr->next->next;
    //     }
        
    //     curr = head;
    //     Node *temp = head->next;
        
    //     while(curr != NULL && curr->next != NULL)
    //     {
    //         linker = curr->next;
    //         curr->next = linker->next;
    //         curr = linker;
    //     }
    //     return temp;
        
    // }
