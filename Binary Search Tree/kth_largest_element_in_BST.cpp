// problem link: https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
    // idea is to do inorder traversal in a reversed manner since we want largest so we will first be going right and right
    
    void solve(Node* root, int key, int &count, bool &check)
    {
        if(root == NULL) return;
        solve(root->right, key, count, check);
        
        if(check == false)count++;
        if(count == key)
        {
            //cout<<root->data;
            count = root->data;
            check = true; // if we don't keep bool check than when function goes back to previous caller everytime it will  do count++ which will change 
            return;
        }
        
        solve(root->left, key, count, check);
    }
    
    int kthLargest(Node *root, int key)
    {
        int count=0;
        bool check = false;
        solve(root, key, count, check);
        
        return count;
    }
