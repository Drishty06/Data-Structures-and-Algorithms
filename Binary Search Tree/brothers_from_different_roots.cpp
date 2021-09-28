// problem link: https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1
// method: we can store elements of one the tree in a set and then
// we can traverse second bst and check if sum-root->data is existing in set or not

    void storing_tree1_in_set(Node* root, unordered_set<int> &s){
        
        if(root == NULL) return;
        // inorder traversal
        storing_tree1_in_set(root->left, s);
        s.insert(root->data);
        storing_tree1_in_set(root->right, s);
    }
    
    void find_element_from_tree2(Node* root, unordered_set<int> &s, int &count, int sum){
        
        if(root == NULL) return;
        
        find_element_from_tree2(root->left, s, count, sum);
        if(s.find(sum - root->data) != s.end()) count++;
        find_element_from_tree2(root->right, s, count, sum);
    }

    int countPairs(Node* root1, Node* root2, int sum)
    {
        unordered_set<int> s;
        storing_tree1_in_set(root1, s);
        int count=0;
        find_element_from_tree2(root2, s, count, sum);
        return count;
    }
