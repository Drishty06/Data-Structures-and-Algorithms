// problem link:https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1
// while coming to leaf node we will check whether it is lying in possible range or not
// for left child lower limit is 1 and upper limit parent node( smaller than parent root )and 
// for right child lower limit parent node and upper limit is previously calculated upper limit

void solve(Node* root, int low, int up, int &ans)
{
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL)
    {
        if(root->data <= low && root->data >= up) ans=1;
        
    }
    solve(root->left, low, root->data-1, ans);
    solve(root->right, root->data+1, up, ans);
}

bool isDeadEnd(Node *root)
{
    int ans=0;
    solve(root, 01, INT_MAX, ans);
    if(ans) return true;
    return false;
}
