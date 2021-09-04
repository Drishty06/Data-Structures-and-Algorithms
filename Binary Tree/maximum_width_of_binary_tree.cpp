// problem link: https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1
    // used the code for level order traversal with a slight change
    int getMaxWidth(Node* node) {
        queue<Node *> q;
        q.push(node);
        int max=0;
        while(q.size() != 0)
        {
            int count = q.size();
            if(count > max) max = count;
            for(int i=0; i<count; i++)
            {
                Node *top = q.front();
                q.pop();
                if(top != NULL) 
                {
                    if(top -> left) q.push(top->left);
                    if(top -> right) q.push(top->right);
                }
            }
            
        }
        return max;
    }
