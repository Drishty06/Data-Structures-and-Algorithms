// problem link: https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
    // this code is similar to that of level order traversal but just changed the order of pushing into the queue since
    // since for right view i wish to push elements in right side first 
    // and then added only the first element of all level into the answer vector
    vector<int> rightView(Node *node)
    {
       vector<int> ans;
        queue<Node *> q;
        q.push(node);
        int idx=0;
        bool check = false;
        while(q.size() != 0)
        {
            int count = q.size();
            check = true;
            for(int i=0; i<count; i++)
            {
                Node *top = q.front();
                q.pop();
                if(top != NULL) 
                {
                    if(check)
                    {
                        ans.push_back(top->data);
                        check = false;
                    }
                    if(top -> right) q.push(top->right);
                    if(top -> left) q.push(top->left);
                }
            }
            
        }
    return ans;
    }
