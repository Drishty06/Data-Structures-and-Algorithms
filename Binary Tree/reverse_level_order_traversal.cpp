// problem link: https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1#
// almost similar code as that of level order traversal the only difference is adding reverse at two places
vector<int> reverseLevelOrder(Node *node)
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
            
            reverse(ans.begin()+idx, ans.end());
            idx += count;
                
        }
        reverse(ans.begin(), ans.end());
        return ans;
}
