// problem link: https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1#
    // basically we are doing simple inorder traversal and storing the previous node
    // then we are making prevNode->next = current node
    
    void solve(Node* root, Node* &prevNode)
    {
        //cout<<root->data<<endl;
        if(root == NULL) return;
        
        if(root->left != NULL) solve(root->left, prevNode);
        
        if(prevNode != NULL) prevNode->next = root;
        prevNode = root;
        
        if(root->right != NULL) solve(root->right, prevNode);
    }
    
    void populateNext(Node *root)
    {
        Node* prevNode = NULL;
        solve(root, prevNode);
    }
