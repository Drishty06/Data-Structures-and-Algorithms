// problem link: https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1
    // idea is that inorder traversal of binary search tree is in sorted order
    // so we first of traverse BT and store it in an array, then sort that array
    // and then make new bst from it by just replacing data
    
    void inorderTraversal(Node* root, vector<int> &binaryTree){
        
        if(root == NULL) return;
        inorderTraversal(root->left, binaryTree);
        binaryTree.push_back(root->data);
        inorderTraversal(root->right, binaryTree);
        
    }
    
    void makeBST(Node* root, vector<int> &binaryTree, int &idx){
        
        if(root == NULL) return;
        makeBST(root->left, binaryTree, idx);
        root->data = binaryTree[idx];
        idx++;
        makeBST(root->right, binaryTree, idx);
        
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> binaryTree;
        inorderTraversal(root, binaryTree);
        sort(binaryTree.begin(), binaryTree.end());
        int idx=0;
        makeBST(root, binaryTree, idx);
        return root;
    }
