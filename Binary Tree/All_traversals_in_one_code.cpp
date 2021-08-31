// preorder inorder postorder in one traversal and one stack.
// Time complexity O(3*N)
// space complexity O(4*N)
// create a stack of (Node, num) type
// follow these rules:
// if num==1: preorder | num++ | node->left
// if num==2: inorder  | num++ | node->right
// if num==3: postorder|       | 
// for more info
void preInPostTraversal(Node* root)
{
  stack<pair<Node*, int>> s;
  s.push(root, 1);
  vector<int> pre, in, post;
  if(root == NULL) return;
  while(! s.empty())
  {
    auto it = s.top();
    s.pop();
    // preorder
    if(it.second == 1)
    {
      pre.push_back(it.first->data);
      it.second++;
      s.push(it);
      if(it.first->left != NULL)
      {
        s.push({it.first->left, 1});
      }
    }
    // inorder
    else if(it.second == 2)
    {
      in.push_back(it.first->data);
      it.second++;
      s.push(it);
      if(it.first->right != NULL)
      {
        s.push({it.first->right, 1});
      }
    }
    // postorder
    else
    {
      post.push_back(it->first->data);
    }
  }
}
