
// problem link: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#
// method 1: i simply used the code of level order traversal 
// but instead of adding all elements to ans vector, i simply add only the first element of every level
vector<int> leftView(Node *node)
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
                    if(top -> left) q.push(top->left);
                    if(top -> right) q.push(top->right);
                }
            }
            
        }
    return ans;
}
