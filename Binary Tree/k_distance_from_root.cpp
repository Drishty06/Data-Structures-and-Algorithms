// problem link: https://practice.geeksforgeeks.org/problems/k-distance-from-root/1
// simply used the code for level order traversal with a little change
// added to vector only when idx = k
vector<int> Kdistance(struct Node *node, int k)
{
  vector<int> ans;
        queue<Node *> q;
        q.push(node);
        int idx=0;
        bool check = true;
        while(q.size() != 0)
        {
            int count = q.size();
            for(int i=0; i<count; i++)
            {
                Node *top = q.front();
                q.pop();
                if(top != NULL) 
                {
                    if(idx == k)
                    {
                        ans.push_back(top->data);
                        check = false;
                    }
                    if(top -> left) q.push(top->left);
                    if(top -> right) q.push(top->right);
                }
            }
            if(check == false) break;
            idx++;
        }
        return ans;
}
