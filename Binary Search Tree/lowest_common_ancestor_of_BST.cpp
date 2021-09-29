// problem link: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1
// simialr to lca of binary tree

Node* LCA(Node *root, int n1, int n2)
{
  if(root == NULL) return NULL;
  if(root->data == n1 || root->data == n2) return root; // case 1      
  Node* lca1 = LCA(root->left, n1, n2);
  Node* lca2 = LCA(root->right, n1, n2);
  if(lca1 != NULL && lca2 != NULL) return root; // case 2
  if(lca1 != NULL) return lca1;
  else return lca2;
}
