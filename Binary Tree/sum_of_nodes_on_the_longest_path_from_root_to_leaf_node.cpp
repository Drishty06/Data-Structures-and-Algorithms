// problem link: https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
// firstly calculate the height of the tree
// then recursively call solve function for root->left and root->right
// also add sum + root->data and dist++
// now if the node is root node and is dist== height and sum > maxi than we update maxi to sum
// else we make sum = 0 and dist = 0

    int heights(struct Node* node){
        if(node == NULL) return 0;
        return max(heights(node->left), heights(node->right))+1;
    }
    
    int maxi = 0;

    void solve(Node *root, int dist, int sum, int height)
    {
        if(root->left == NULL && root->right == NULL)
        {
            sum = sum + root->data;
            dist++;
            // cout<<sum<<endl;
            // cout<<dist<<endl;
            if(dist == height && sum > maxi)
            {
                maxi = sum;
            }
            sum = 0;
            dist = 0;
            return;
        }
        if(root->left) solve(root->left, dist+1, sum+root->data, height);
        if(root->right)solve(root->right, dist+1, sum+root->data, height);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int height = heights(root);
        solve(root, 0, 0, height);
        return maxi;
    }
