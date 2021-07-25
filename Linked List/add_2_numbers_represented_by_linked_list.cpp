// problem link: https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#
 // method:
    // idea is to first reverse both the lists and then perfom addition like we used to perform in schools using carry
    // continue adding and make a variable carry
    // later, reverse again and return new head
    
    struct Node* reverseList(struct Node *head) // for reversing the list
    {
        Node *prev = NULL;
        Node *next = NULL;
        Node *curr = head;
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverseList(first); // Node representing head of first node after reversing
        second = reverseList(second); // Node repesenting head of second node after reversing
        
        Node *new_head = NULL; // head of the new list
        Node *third = NULL;    // for iterating in the loop for newly formed thied list which stores the answer
        Node *temp = NULL;     // used for storing the values so that they can be added to the newly formed list
        int carry = 0, sum=0; 
        
        while(first != NULL || second != NULL || carry) // all the three condition are extremely important
        // it is possible that any of first list or second list can become null therefore first two condition handle those two conditions
        // last condition is the making this code extremely good 😍
        // since there may be cases where lets say we have 99 + 3 in such cases the last digit ie., carry is the only thing to be added
        {
            sum = carry + (first != NULL ? first->data : 0) + (second != NULL ? second->data : 0);
            carry = sum/10; // carry
            Node *temp = new Node(sum % 10); // new node
            if(new_head == NULL) // if that's the first element in the third list then wee make tham the new head
            {
                new_head = temp;
                third = new_head;
            }
            else 
            {
                third->next = temp;
                third = third->next; // this line is to be used only after iteration of setting up the head, else it will give segmentation fault. since we have to run one step backward 
            }
            first = first != NULL? first->next : first; // updating first and second pointera and handling the cases when any of them becomes null
            second = second != NULL? second->next : second;
               
        }
        third = reverseList(new_head); // reversing the list again
        return third;
    }
