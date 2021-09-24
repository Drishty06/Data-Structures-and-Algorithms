// problem link: https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1
// idea is that if key is greater than current node's data then make current = current->right
// else if key is smaller than current node's then make current = current->left
// else if the current node's data is equal to key than no need to change anything, simply return root
// iterative solution

Node* insert(Node* root, int key) {
    Node *keynode = new Node(key);
    Node *parent = NULL;
    Node *curr = root;
    
    while(curr != NULL)
    {
        parent = curr;
        
        if(curr->data < key) curr = curr->right;
        else if(curr->data > key) curr = curr->left;
        else return root;
    }
    if(parent == NULL) return keynode;
    
    if(parent->data < key) parent->right = keynode;
    else parent->left = keynode;
    return root;   
}
