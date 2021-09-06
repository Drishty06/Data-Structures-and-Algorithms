// problem link: https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1
    
    bool leafLevel(Node* node, int level, int *firstLevel)
    {
        if(node == NULL) return true; // if node is null
        if(node->left == NULL && node->right == NULL) // leaf node
        {
            if(*firstLevel == 0) // leaf node seen for the first time
            {
                *firstLevel = level; // noting first leaf node level
                return true;
            }
            else
            {
                return (level == *firstLevel); // if leaf node is not for the first time
            }
        }
        // if not a leaf node then recursively call for its left and right
        return (leafLevel(node->left, level+1, firstLevel) && leafLevel(node->right, level+1, firstLevel));
    }
    
    bool check(Node *root)
    {
       int level=0;
       int firstLevel = 0;
       return leafLevel(root, level, &firstLevel);
    }
