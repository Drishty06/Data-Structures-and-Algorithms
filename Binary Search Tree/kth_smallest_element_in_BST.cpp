
    // problem link: https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1
    // refer kth largest problem 
    // the code is similar to sa kth largest elemnt with a slight change

    void solve(Node* root, int key, int &count, bool &check, int &ans)
    {
        if(root == NULL) return;
        solve(root->left, key, count, check, ans);
        
        count++;
        if(count == key)
        {
            //cout<<root->data;
            ans = root->data;
            return;
        }
        
        solve(root->right, key, count, check,ans);
    }
    
    int KthSmallestElement(Node *root, int key) {
        int count=0, ans = -1;
        bool check = false;
        solve(root, key, count, check, ans);
        
        return ans;
    }
