// problem link: https://practice.geeksforgeeks.org/problems/preorder-traversal/1#
void solve(Node *root, vector<int> &ans)
{
    if(root != NULL)
    {
        ans.push_back(root->data);
        solve(root->left, ans);
        solve(root->right, ans);
    }
}
vector <int> preorder(Node* root)
{
    vector <int> ans;
    solve(root, ans);
    
    return ans;
}
