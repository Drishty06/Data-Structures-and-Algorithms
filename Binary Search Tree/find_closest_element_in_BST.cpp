
	// problem link: https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1
	// idea is to simply do a traversal and update the closest element every time
	
	void inorderTraversal(Node* root, int k, int &minDiff){
	    
	    if(root == NULL) return;
	    inorderTraversal(root->left, k, minDiff);
	    if(abs(k - root->data) < minDiff)
	    {
	        minDiff = abs(k - root->data);
	    }
	    inorderTraversal(root->right, k, minDiff);
	    
	}
	
    int minDiff(Node *root, int k)
    {
        int minDiff = INT_MAX;
        inorderTraversal(root, k, minDiff);
        return minDiff;
    }
