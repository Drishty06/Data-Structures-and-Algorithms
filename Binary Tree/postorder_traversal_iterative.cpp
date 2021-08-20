// problem link : https://practice.geeksforgeeks.org/problems/postorder-traversal/1
// iteravtive solution
vector <int> postOrder(Node* root)
{
     vector<int> ans;
       stack<Node*> s;
       Node *curr = root;
       Node *prev = NULL;
       
       while(curr != NULL || s.empty() == false)
       {
           if(curr != NULL)
           {
               s.push(curr);
               curr = curr->left;
           }
           else
           {
               curr = s.top();
               if(curr->right == NULL || curr->right == prev)
               {
                   ans.push_back(curr->data);
                   s.pop();
                   prev = curr;
                   curr = NULL;
               }
               else
               {
                   curr = curr->right;
               }
           }
       }
       return ans;
}
