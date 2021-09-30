// problem link: https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1/?track=P100-Binary%20Search%20Tree&batchId=197
    // idea is to store elements of each tree in sorted form by inorder traversal
    // then apply two pointer approach to merge them into single vector
    // while performing two pointer approach:
    // 1. if numbers are equal we increment both the pointers and push back both of them into the final vector
    // 2. if a if one element is lesser than we push it to the vector and increment only that pointer
    // 3. if we reach to the end of any vector we stop
    // 4. to cover rest of the elements we simple push rest of elements of incomplete vector
    
    void inorder(Node* root, vector<int> &vec)
    {
        if(root == NULL) return;
        
        inorder(root->left, vec);
        vec.push_back(root->data);
        inorder(root->right, vec);
    }
    
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> bst1;
        inorder(root1, bst1);
        
        vector<int> bst2;
        inorder(root2, bst2);
        
        int size1 = bst1.size();
        int size2 = bst2.size();
        int ptr1 = 0, ptr2 = 0;
        
        vector<int> merged;
        
        while(ptr1 < size1 && ptr2 < size2)
        {
            if(bst1[ptr1] == bst2[ptr2])
            {
                merged.push_back(bst1[ptr1]);
                merged.push_back(bst2[ptr2]);
                ptr1++;
                ptr2++;
            }
            
            else if(bst1[ptr1] < bst2[ptr2])
            {
                merged.push_back(bst1[ptr1]);
                ptr1++;
            }
            
            else if(bst2[ptr2] < bst1[ptr1])
            {
                merged.push_back(bst2[ptr2]);
                ptr2++;
            }
        }
        
        while(ptr1 < size1)
        {
            merged.push_back(bst1[ptr1]);
            ptr1++;
        }
        
        while(ptr2 < size2)
        {
            merged.push_back(bst2[ptr2]);
            ptr2++;
        }
        
        return merged;
    }
