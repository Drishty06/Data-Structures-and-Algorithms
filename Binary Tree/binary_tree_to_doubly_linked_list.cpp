// problem link: https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1#
    
    void conversion(Node *node, Node *&head, Node *&prev)
    {
        if(node == NULL) return;
        conversion(node->left, head, prev); // recursively calling for left subtree
        
        if(prev == NULL) head = node; // if that is first node then we make it head
        else
        {
            node->left = prev;   
            prev->right = node;
        }
        prev = node;
        
        conversion(node->right, head, prev); // recursively calling for right subtree
    }
    
    Node * bToDLL(Node *root)
    {
        Node *head = NULL;
        Node *prev = NULL;
        conversion(root, head, prev);
        return head;
    }
