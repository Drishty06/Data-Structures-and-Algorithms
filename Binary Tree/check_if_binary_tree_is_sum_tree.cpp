// problem link: https://practice.geeksforgeeks.org/problems/sum-tree/1
    // used the same code of convert to sum tree with a slight change 
    
    int sumTree(Node* root, int &ans)
    {
        if(root == NULL) return 0;
        int sum = root->data;
        int left_sum = sumTree(root->left, ans);
        int right_sum = sumTree(root->right, ans);
        
        if((!(root->left == NULL && root->right == NULL)) && root->data != left_sum + right_sum) 
        {
            ans = 0;
        }
        return sum+left_sum+right_sum;
    }
    
    bool isSumTree(Node* root)
    {
        int ans = 1;
        sumTree(root, ans);
        return ans;
    }
