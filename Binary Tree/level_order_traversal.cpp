
    // problem link: https://practice.geeksforgeeks.org/problems/level-order-traversal/1
    // method 1:
    // idea:
    // 1. we use queue since answer is following fifo concept
    // 2. insert root node and null node firstly into the queuq
    // 3. reason of adding null pointer is that that it will show us when the current level is over
    // 4. we pick up top element of queue and if that is not null then we insert its left child and right child into the queue
    // 5. if thats a null pointer then we simply insert another null pointer so that it denotes end of current level
    // vector<int> levelOrder(Node* node)
    // {
    //     vector<int> ans;
    //     queue<Node *> q;
    //     q.push(node);
    //     q.push(NULL);
    //     while(q.size() > 1)
    //     {
    //         Node *top = q.front();
    //         q.pop();
    //         if(top != NULL) 
    //         {
    //             ans.push_back(top->data);
    //             if(top -> left) q.push(top->left);
    //             if(top -> right) q.push(top->right);
    //         }
    //         else
    //         {
    //             q.push(NULL);
    //         }
                
    //     }
    //     return ans;
    // }
    
    // method 2:
    
    vector<int> levelOrder(Node* node)
    {
        vector<int> ans;
        queue<Node *> q;
        q.push(node);
        int idx=0;
        while(q.size() != 0)
        {
            int count = q.size();
            for(int i=0; i<count; i++)
            {
                Node *top = q.front();
                q.pop();
                if(top != NULL) 
                {
                    ans.push_back(top->data);
                    if(top -> left) q.push(top->left);
                    if(top -> right) q.push(top->right);
                }
            }
            
        }
        return ans;
    }
