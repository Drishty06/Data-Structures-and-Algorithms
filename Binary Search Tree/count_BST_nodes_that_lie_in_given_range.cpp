// problem link: https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1
// idea :
// if node is within the range then increment count and call recursively for left and right subtrees
// if node is smaller than l than ofc nodes on its left are definitely not going to be in the range so recursively call only for right subtree
// if node is greater than r than ofc nodes on its right are definitely not going to be in the range so recursively call for only left subtree

void solve(Node *root, int l, int h, int &count)
{
    if(root == NULL) return;
    
    if(root->data >= l && root->data <= h) 
    {
        count++;
        solve(root->left, l, h, count);
        solve(root->right, l, h, count);
    }
    
    else if(root->data < l) solve(root->right, l, h, count);
    
    else solve(root->left, l, h, count);
}

int getCount(Node *root, int l, int h)
{
   int count=0;
   solve(root, l, h, count);
   return count;
}
