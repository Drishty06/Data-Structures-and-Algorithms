// problem link: https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1#
// idea is to check whether nthe element is lying in range or not
// root will have the range INT_MIN to INT_MAX
// as we go left we change max limit as pre[pos] and as we go right we change min limit as pre[pos]

Node* build(int pre[], int n, int &pos, int min, int max){
    
    if(pos == n) return NULL;
    int element = pre[pos];
    if(element > max || element < min) return NULL;
    
    Node* root = newNode(element);
    pos++;
    
    root->left = build(pre, n, pos, min, element);
    root->right = build(pre, n, pos, element, max);
    
    return root;
}

Node* constructTree(int pre[], int size)
{
    if(size == 0) return NULL;
    int pos = 0;
    return build(pre, size, pos, INT_MIN, INT_MAX);
}
