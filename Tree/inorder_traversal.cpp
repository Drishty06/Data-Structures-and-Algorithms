// problem link: https://practice.geeksforgeeks.org/problems/inorder-traversal/1#
    vector<int> inOrder(Node* root) {
        
        if(root != NULL)
        {
            inOrder(root->left);
            ans.push_back(root->data);
            inOrder(root->right);
        }
        return ans;
    }
