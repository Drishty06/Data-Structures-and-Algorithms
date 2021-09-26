// problem link: https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1/?track=P100-Binary%20Search%20Tree&batchId=197
// just a slight change in floor of bst problem
int findCeil(Node* root, int key) {
    int ans=-1;
    while(root != NULL)
    {
        if(root->data == key) return root->data;
        else if(root->data < key) root = root->right;
        else if(root->data > key)
        {
            ans = root->data;
            root = root->left;
        }
    }
    return ans;
}
