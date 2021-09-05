// Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    // problem link: https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#
    // store value of current node in actual tree then recursively call for its left, recursively call for its right
    // add the values which came from recursive calls and return cuurent node data + current node actual data
    int sumTree(Node* root)
    {
        if(root == NULL) return 0;
        int sum = root->data;
        root->data = sumTree(root->left) + sumTree(root->right);
        return sum+root->data;
    }
    
    void toSumTree(Node *node)
    {
        sumTree(node);
    }
