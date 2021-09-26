// problem link: https://practice.geeksforgeeks.org/problems/check-for-bst/1
    // method 1: maintain a range in which every node is supposed to be
    // if going towards left, change max limit
    // if going towards right, change min limit
    
    // method 2: a bt is bst if and only if its inorder traversal is sorted
    // traverse the tree in inorder manner
    // maintain a global variable prev which ensures if prev one is smaller
    // no need to use any auxiliary array
    
    // method 1:
    bool solve(Node* root, int min, int max)
    {
        if(root == NULL) return true;
        
        if(root->data > min && root->data < max ) 
        {
            return solve(root->left, min, root->data) && solve(root->right, root->data, max);
        }
        else return false;
    }
    
    bool isBST(Node* root) 
    {
        if(solve(root, INT_MIN, INT_MAX)) return true;
        return false;
    }
