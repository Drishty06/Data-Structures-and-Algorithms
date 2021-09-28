
    // problem link:https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1
    // method 1: do an inorder traversal and store in a vector and then use two pointer approach to find the pairs
    // method 2: while travering the tree for every node search for sum-root->data into the left tree if it is not present than n store it into the set .
    // also check if set contains sum-root->data or not and check for right subtree
    
    // method 2:
    
    int find(Node* root, int target, unordered_set<int> &s)
    {
        if(root == NULL) return 0;
        if(find(root->left, target, s) == 1) // present
        {
            return 1;
        }
        if(s.find(target - root->data) != s.end())
        {
            return 1;
        }
        else
        {
            s.insert(root->data);
        }
        
        return find(root->right, target, s);
    }
    
    int isPairPresent(struct Node *root, int target)
    {
        unordered_set<int> s;
        if(find(root, target, s)) return 1;
        return 0;
        
    }
        
