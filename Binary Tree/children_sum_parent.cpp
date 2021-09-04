// problem link: https://practice.geeksforgeeks.org/problems/children-sum-parent/1#
    // initialised ans with 1
    // if chilren sum is not equal to sum than ans=0 else recursively calling for root->left and root->right
    
    void childrenSum(int &ans, Node* root)
    {
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL) return;
        
        int sum = 0;
        
        if(root->left) sum += root->left->data;
        if(root->right) sum += root->right->data;
        
        if(root->data != sum) 
        {
            ans = 0;
            return;
        }
        if(root->left) childrenSum(ans, root->left);
        if(root->right) childrenSum(ans, root->right);
        
    }
    
    int isSumProperty(Node *root)
    {
     int ans=1;
     childrenSum(ans, root);
     return ans;
    }
