// problem link: https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1#
// balanced tree: height of binary tree is at max log2 (N) 
//                                    OR 
//                Binary tree in which height of the left and the right sub-trees of every node may differ by at most 1
// used the same code to find the left height and right height and changed it slightly
 
int solve(int &maxi, Node* root, int &ans) 
{
      if(root == NULL) return 0;
      int left_height = solve(maxi, root->left, ans);
      int right_height = solve(maxi, root->right, ans);
      if(left)
      if(abs(left_height - right_height) > 1) ans=0;
      return 1+max(left_height, right_height);
 }
    bool isBalanced(Node *root)
    {
        int maxi=0;
        int ans=1;
        solve(maxi, root, ans);
        if(ans == 1) return true;
        return false;
    }
