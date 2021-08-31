// problem link : https://practice.geeksforgeeks.org/problems/postorder-traversal/1
void solve(Node *root, vector<int> &ans)
{
    if(root != NULL)
    {
        solve(root->left, ans);
        solve(root->right, ans);
        
        ans.push_back(root->data);
    }
}
vector <int> postOrder(Node* root)
{
    vector <int> ans;
    solve(root, ans);
    
    return ans;
}
