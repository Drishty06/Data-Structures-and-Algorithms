// problem link: https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1
  // idea: inorder traversal of bst is sorted. using this fact we have to find the elements which are violating this
  // there can be 2 cases in that:
  // 1. the nodes which are to be swapped are adjacent 
  // 2. not adjacent
  // basically the problem is reduced to finding two elements from array which are making array unsorted
  
    Node* prev = NULL;
    Node* first = NULL;
    Node* second = NULL;
    
    void solve(Node* root)
    {
        if(root == NULL) return;
        solve(root->left);
        
        if(prev != NULL && root->data < prev->data)
        {
            if(first == NULL) first = prev;
            second = root;
        }
        prev = root;
        
        solve(root->right);
    }
    
    void correctBST( struct Node* root )
    {
        solve(root);
        swap(first->data, second->data);
        return;
    }
