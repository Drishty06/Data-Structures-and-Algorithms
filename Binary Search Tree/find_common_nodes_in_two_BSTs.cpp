// problem link: https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1
    // store one of the tree in set and 
    // then traverse another bst and check if element already present in set
    
    void adding_elements_of_tree1(Node *root, unordered_set<int> &s)
    {
        if(root == NULL) return;
        adding_elements_of_tree1(root->left, s);
        s.insert(root->data);
        adding_elements_of_tree1(root->right, s);
    }
    
    void tree2_traversal(Node* root, unordered_set<int> &s, vector<int> &common)
    {
        if(root == NULL) return;
        tree2_traversal(root->left, s, common);
        if(s.find(root->data) != s.end())
        {
            common.push_back(root->data);
        }
        tree2_traversal(root->right, s, common);
    }
    
    vector <int> findCommon(Node *root1, Node *root2)
    {
        unordered_set<int> s;
        adding_elements_of_tree1(root1, s);
        vector<int> common;
        tree2_traversal(root2, s, common);
        return common;
    }
