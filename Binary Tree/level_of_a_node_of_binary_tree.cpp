// problem link: if the node is a leaf node, then we check if thats equal to target then we set level+1 as ans
    // else we make level = 0 for next recursive calls
    // if non-leaf node data is equal to target, then we set level+1 as answer, else we recursively call for left and right subtrees
    
    void nodeToRoot(Node *root, int n, int level, int* ans)
    {
        if(root->left == NULL && root->right == NULL)
        {
            if(root->data == n) 
            {
                *ans = level+1;
                return;
            }
            else 
            {
                level= 0;
                return;
            }
        }
        
        if(root->data == n) 
        {
            *ans = level+1;
            return;
        }
        if(root->left) nodeToRoot(root->left, n, level+1, ans);
        if(root->right) nodeToRoot(root->right, n, level+1, ans);
    }
    
    int getLevel(struct Node *root, int target)
    {
        int ans1 =0;
        nodeToRoot(root, target, 0, &ans1);
        int dist1 = ans1;
        if(dist1 == -1) return 0;
        return dist1;
    }
