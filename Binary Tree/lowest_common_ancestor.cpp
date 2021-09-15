
    //Function to return the lowest common ancestor in a Binary Tree.
    
    // method 1: naive
    // we find two paths from root to n1 and root to n2
    // and from these two path vectors, the element before the first uncommon element is the lca
    
    // bool findPath(Node *root, vector<Node *> &p, int n)
    // {
    //     if(root == NULL) return false;
    //     p.push_back(root);
    //     if(root->data == n) return true;
    //     if(findPath(root->left, p, n) || findPath(root->right, p, n)) return true;
    //     p.pop_back();
    //     return false;
    // }
    
    // Node* lca(Node* root ,int n1 ,int n2 )
    // {
    //     vector <Node*> path1, path2;
    //     if(findPath(root, path1, n1) == false || findPath(root, path2, n2) == false) return NULL;
    //     // traversing to find the element before the first uncommon element
    //     //cout<<path1.size()<<path2.size();
    //     int i;
    //     for(i=0; i<path1.size()-1 && i<path2.size()-1; i++)
    //     {
            
    //         if(path1[i+1] != path2[i+1]) 
    //         {
    //             return path1[i];
    //         }
            
    //     }
        
    // }
    
    // method 2: efficient method
    // this method will NOT work when either of n1 or n2 are present
    // we have following 4 cases while traversing the tree:
    // 1. current node's data = n1 or n2
    // 2. one of the subtree contains n1 and another contains n2
    // 3. one subtree contains n1 and n2 both
    // 4. none of the subtree contains n1 or n2
    
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
