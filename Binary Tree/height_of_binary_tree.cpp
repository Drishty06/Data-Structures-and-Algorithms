//Function to find the height of a binary tree.
    
    // problem link: https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
    int height(struct Node* node){
        if(node == NULL) return 0;
        return max(height(node->left), height(node->right))+1;
    }
