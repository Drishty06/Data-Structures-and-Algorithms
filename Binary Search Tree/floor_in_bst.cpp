// problem link: https://practice.geeksforgeeks.org/problems/implementing-floor-in-bst/1/?track=P100-Binary%20Search%20Tree&batchId=197#
// 1. root->data == key : simply return root->data
// 2. root->data > key  : root = root->left
// 3. root->data < key  : current root can possibly be an answer so store that in a variable

int floor(Node* root, int key) 
{
    int ans=-1;
    while(root != NULL)
    {
        if(root->data == key) return root->data;
        else if(root->data > key) root = root->left;
        else if(root->data < key)
        {
            ans = root->data;
            root = root->right;
        }
    }
    return ans;
}
