// problem link: https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1#
// the question is to find successor and predecessor of number 
// if the number is not present in bst then return the values between which it will lie
// problem link: https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1#
// 3 cases:
// 1. root->data = key: successor is left most node of right child
//                   predecessor is rightmost node of left child
//                   according to this we find suc and pre
// 2. root->data > key: root = root->left 
//                      current node can be a successor so storing it as suc = root
// 3. root->data < key: root = root->right
//                      current node can be a predecessor so storing it as pre = root

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root == NULL) return;
    if(root->key == key) // case 1
    {
        if(root->left != NULL) // for predecessor
        {
            Node* temp = root->left;
            while(temp->right != NULL)
            {
                temp = temp->right;
            }
            pre = temp;
        }
        
        if(root->right != NULL) // for successor
        {
            Node* temp = root->right;
            while(temp->left != NULL)
            {
                temp = temp->left;
            }
            suc = temp;
        }
        return;
    }
    
    if(root->key > key) // case 2
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    
    if(root->key < key) // case 3
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}
