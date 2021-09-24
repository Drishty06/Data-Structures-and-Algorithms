// problem link: https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1#
int minValue(Node* curr) {
    while(curr != NULL && curr->left != NULL)
    {
        if(curr->left) curr = curr->left;
        else return curr->data;
    }
    return curr->data;
}
