// problem link: https://practice.geeksforgeeks.org/problems/max-and-min-element-in-binary-tree/1
// recursive solution where we simply compare data of root with its left and with its right and return maximum
// time complexity = O(n)
// space complexity = O(height of binary tree)
    int findMax(Node *root)
    {
        if(root == NULL) return INT_MIN;
        return max(root->data, (max(findMax(root->left), findMax(root->right))));
    }
    int findMin(Node *root)
    {
        if(root == NULL) return INT_MAX;
        return min(root->data, (min(findMin(root->left), findMin(root->right))));
    }
