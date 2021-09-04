// problem link: https://practice.geeksforgeeks.org/problems/k-distance-from-root/1
// method 1
// simply used the code for level order traversal with a little change
// added to vector only when idx = k
// vector<int> Kdistance(struct Node *node, int k)
// {
//   vector<int> ans;
//         queue<Node *> q;
//         q.push(node);
//         int idx=0;
//         bool check = true;
//         while(q.size() != 0)
//         {
//             int count = q.size();
//             for(int i=0; i<count; i++)
//             {
//                 Node *top = q.front();
//                 q.pop();
//                 if(top != NULL) 
//                 {
//                     if(idx == k)
//                     {
//                         ans.push_back(top->data);
//                         check = false;
//                     }
//                     if(top -> left) q.push(top->left);
//                     if(top -> right) q.push(top->right);
//                 }
//             }
//             if(check == false) break;
//             idx++;
//         }
//         return ans;
// }

// method 2 recursive

void solve(vector<int> &ans,struct Node *root, int k)
{
  if(root == NULL) return;
  if(k == 0) ans.push_back(root->data);
  else
  {
    solve(ans, root->left, k-1);
    solve(ans, root->right, k-1);
  }
}
vector<int> Kdistance(struct Node *node, int k)
{
  vector<int> ans;
  solve(ans, node, k);
  return ans;
}

