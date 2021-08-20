
// problem link: https://practice.geeksforgeeks.org/problems/size-of-binary-tree/1
// method 1
// i simply copied the code for traversal of tree and instead of returning vector of elements, i simply returned vector size


// void solve(Node *root, vector<int> &ans)
// {
//     if(root != NULL)
//     {
//         ans.push_back(root->data);
//         solve(root->left, ans);
//         solve(root->right, ans);
//     }
// }

// int size(Node* root) 
// {
//     vector <int> ans;
//     solve(root, ans);
    
//     return ans.size();
// }

// int getSize(Node* node)
// {
//   int answer = size(node);
//   return answer;
// }
//}


// method 2:
int getSize(Node* node)
{
   if(node == NULL) return 0;
   return 1+getSize(node->left)+getSize(node->right);
}

