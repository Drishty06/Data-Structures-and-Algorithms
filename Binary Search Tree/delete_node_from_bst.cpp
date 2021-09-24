// problem link: https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1
// for deleting the node there are three cases:
// 1. root->left is NULL : in this case we simply have to assign the left of its parent to right of its right chils
// 2. root->right is NULL: similar to above case
// 3. none of root left or right is null. ie., it has two children
//    in that case, we have to find the successor of the root which is just greater than it
//    so basically we want leftmost child of right child of the root

Node* getSuccessor(Node *curr)
{
    curr = curr->right; 
    while(curr != NULL && curr->left != NULL) // to get the leftmost child of the right child of the root
    {
        curr = curr->left;
    }
    return curr;
}

Node *deleteNode(Node *root, int key) {
    // first three lines are exact similar to that of recursive insertion code
    
    if(root == NULL) return root;
    if(root->data > key) root->left = deleteNode(root->left, key);
    else if(root->data < key) root->right = deleteNode(root->right, key);
    
    else // the condition in which root->data == key
    {
        if(root->left == NULL) // simple case: assign parent's->right = root's right child
        {
            Node* temp = root->right; 
            delete root;
            return temp;
        }
        
        else if(root->right == NULL) // simple case: same as above one
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        else // complex case when we have to find LEFTMOST root of RIGHT CHILD of root
        {
            Node* succ = getSuccessor(root);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
        
    }
}
