// problem link: https://practice.geeksforgeeks.org/problems/construct-tree-1/1
    // we can construct binary tree only with the help of inorder+preorder or inorder+postorder combinations
    // preorder+postorder combination is NOT sufficient to contruct binary tree
    // here preorder traversal acts as collection of roots and inorder defines that which is left subtree and which is right subtree

    
    int preIndex = 0;
    Node* solve(int in[], int pre[], int start, int end, int n)
    {
        if(start > end) return NULL;
        Node* root = new Node(pre[preIndex++]); // constructing head node according to element in preorder traversal
        
        int inIndex;  
        for(int i=start; i<=end; i++) // finding in inorder traversal that where the element found from preorder is located
        {
            if(in[i] ==  root->data)
            {
                inIndex = i;
                break;
            }
        }
        root->left = solve(in, pre, start, inIndex-1, n); 
        root->right = solve(in, pre, inIndex+1, end, n);
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        Node* ans = solve(in, pre, 0, n-1, n);
        return ans; 
    }
