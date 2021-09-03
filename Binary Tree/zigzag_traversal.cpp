// problem link: https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1#
    // using the same code of level order traversal with one slight change
    // reversing the output after every alternate levels
    
    vector <int> zigZagTraversal(Node* node)
    {
    	vector<int> ans;
        queue<Node *> q;
        q.push(node);
        int idx=0, temp=0;
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
            if(idx%2 != 0) reverse(ans.begin()+temp, ans.end());
            idx++;
            temp+=count;
        }
        return ans;
    }
