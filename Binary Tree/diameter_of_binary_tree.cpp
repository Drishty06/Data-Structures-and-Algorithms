  // problem link:https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
  // idea is to find left height and right height for every node 
  // and the maximum of summation of both is the answer
  // this program is very much similar to that of height of binary tree
  int solve(int &maxi, Node* root)
  {
      if(root == NULL) return 0;
      int left_height = solve(maxi, root->left);
      int right_height = solve(maxi, root->right);
      maxi = max(left_height + right_height + 1, maxi);
      return 1+max(left_height, right_height);
  }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        int maxi=0;
        solve(maxi, root);
        return maxi;
        
    }
