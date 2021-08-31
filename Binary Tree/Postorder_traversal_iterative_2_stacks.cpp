// problem link : https://practice.geeksforgeeks.org/problems/postorder-traversal/1
// iterative solution using two stacks
// issue with post order. why it is complicated?
// ans: because it requires two signals: 1. if left subtree is finished 2. if right subtree is finished
// idea is that one stack will be storing left elements and other will be storing the right elements
vector <int> postOrder(Node* root)
{
     vector<int> ans;
     stack<Node*> curr;
     if(root == NULL) return ans;
     stack<Node*> s1, s2;
     s1.push(root);
     while(! s1.empty())
     {
       root = s1.pop();
       s2.push(root);
       if(root->left != NULL) s1.push(root->left);
       if(root->right != NULL) s2.push(root->right);
     }
     while(! s2.empty())
     {
       ans.push_back(s2.top()->data);
       s2.pop();
     }
     return ans;
}
