// problem link:https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
// methods:
    // 1. Naive: O(n^2): traverse through whole linked list and once we reach last node we use another loop to check if node->next = current node (by iterating till n-1 th node)
    // 2. Modify structure of node: O(n): we add bool variable = visited inside the structure of linked list. we traverse through the linked list once and if last node is connected back to any of the nodes, node->next will then point to a node whose visited is true. if that occurs that means there exists a loop
    // 3. using dummy node: using a temp node, we point the next of every node to the temp node, and after reaching the last node, if loop is present then we reach to a node which already has its next pointed to the temp node , and that's how we detect that loop is present
    // 4. using sets
    // 5. floyd cycle detection - (slow fast pointers)
    
    // method | time complexity |space complexity | drawbacks
    //   1.   |      o(n^2)     |       o(1)      | n^2 time complexity
    //   2.   |      o(n)       |       o(1)      | modifying structure is not allowed generally
    //   3.   |      o(n)       |       o(1)      | by pointing next of node to dummy node is equivalent to making changes in original linked list which is may/may not be allowed
    //   4.   |      o(n)       |       o(n)      | using extra space for sets
    //   5.   |      o(n)       |       o(1)      | none - the best among mentioned methods 
    
    
    bool detectLoop(Node* head)
    {
        Node *temp = new Node(NULL);
        Node *curr = head;
        while(curr != NULL)
        {
            if(curr->next == NULL) return false;
            if(curr->next == temp) return true;
            // since we are changing curr->next = temp therefore we loose contact with rest of the elements of the linked list as we broke the link
            // so we need to make another variable which maintains contact with furthur elements of linked list
            Node *linker = curr->next;
            // now as we stored curr->next in the linker, we have the address to next elements, so we can change curr->next to temp
            curr->next = temp;
            curr = linker;
        }
        return false;
        
    }
    
    // idea is to traverse through the loop and store the node into unordered set. if we encounter a node again then condition written in loop will return true
    // bool detectLoop(Node* head)
    // {
    //     unordered_set<Node *> s;
        
    //     for(Node *curr=head; curr!=NULL; curr=curr->next)
    //     {
    //         if(s.find(curr) != s.end()) return true;
    //         s.insert(curr);
    //     }
    //     return false;
    // }
    
    // bool detectLoop(Node* head)
    // {
    //   Node *slow = head;
    //   Node *fast = head;
    //   while(fast != NULL && fast->next != NULL)
    //   {
    //       slow = slow->next;
    //       fast = fast->next->next;
    //       if(slow == fast) return true;
    //   }
    //   return false;
    // }
