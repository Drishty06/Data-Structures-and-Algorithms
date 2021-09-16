// problem link: https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
    // preorder traversal and using -1 for null
    
    void serialization(Node *root, vector <int> &ans)
    {
        if(root == NULL)
        {
            ans.push_back(-1);
            return;
        }
        
        ans.push_back(root->data);
        serialization(root->left, ans);
        serialization(root->right, ans);
    }
    
    vector<int> serialize(Node *root) 
    {
        vector <int>ans;
        serialization(root, ans);
        
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    
    int idx = 0;
    Node * deSerialize(vector<int> &arr)
    {
        if(idx == arr.size()) return NULL;
        int value = arr[idx++];
        if(value == -1) return NULL;
        Node *root = new Node(value);
        root->left = deSerialize(arr);
        root->right = deSerialize(arr);
        return root;
    }
