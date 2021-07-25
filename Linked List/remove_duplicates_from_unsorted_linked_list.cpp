// problem link: https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1#
Node * removeDuplicates(Node *head) 
    {
        if(head==NULL || head->next==NULL) return head;
        unordered_set <int> s;
        Node *curr = head;
        Node *prev = head;
        Node *temp = NULL;
        bool check = false;
        while(curr != NULL)
        {
            if(s.find(curr->data) != s.end()) 
            {
                temp = curr;
                prev->next = curr->next;
                delete(curr);
                check = true;
            }
            else 
            {
                s.insert(curr->data);
                temp = curr;
            }
            
            if(curr != head && check == false) prev = prev->next;
            curr = temp->next;
            check = false;
        }
        return head;
    }
