// problem link: https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
    // LCA(lowest common ancestor) and use this formula 
    // Dist(n1, n2) = Dist(root, n1) + Dist(root, n2) - 2*Dist(root, lca) 
    // for node to root distance, it is simply similar to finding level of a particular node
    
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root == NULL) return NULL;
        if(root->data == n1 || root->data == n2) return root; // case 1
        Node* lca1 = lca(root->left, n1, n2);
        Node* lca2 = lca(root->right, n1, n2);
        if(lca1 != NULL && lca2 != NULL) return root; // case 2
        if(lca1 != NULL) return lca1;
        else return lca2;
        
    }
    
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
    
    int findDist(Node* root, int n1, int n2) {
        Node* Lca = lca(root, n1, n2);
        
        int ans1 =0;
        nodeToRoot(root, n1, 0, &ans1);
        int dist1 = ans1-1;
        // cout<<dist1;
        
        int ans2= 0;
        nodeToRoot(root, n2, 0, &ans2);
        int dist2 = ans2-1;
        // cout<<dist2;
        
        int ans3 =0;
        nodeToRoot(root, Lca->data, 0, &ans3);
        int lcaDist = ans3-1;
        // cout<<lcaDist;
        
        return (dist1+dist2 - (2*lcaDist));
    }
