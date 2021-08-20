// problem link: https://practice.geeksforgeeks.org/problems/inorder-traversal/1#
// iterative solution
    vector<int> inOrder(Node* root) 
    {
       vector<int> ans;
       stack<Node*> s;
       Node *curr = root;
       while(curr != NULL || s.empty() == false)
       {
           // for left subtree
           while(curr != NULL)
           {
               s.push(curr);
               curr = curr->left;
           }
           curr = s.top();
           s.pop();
           ans.push_back(curr->data); // for root
           curr = curr->right; // for right subtree
       }
       return ans;
    }
