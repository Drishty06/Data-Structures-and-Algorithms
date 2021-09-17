 
    // problem link: https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1
    // 1) Data of n1 and n2 is same.
    // 2) One of the following two is true for children of n1 and n2
    //   a) Left child of n1 is isomorphic to left child of n2 and right child of n1 is isomorphic to right child of n2.
    //   b) Left child of n1 is isomorphic to right child of n2 and right child of n1 is isomorphic to left child of n2.
    
    bool isIsomorphic(Node *root1,Node *root2)
    {
         if (root1 == NULL && root2 == NULL) return true;
 
         if (root1 == NULL || root2 == NULL) return false;
         
         if (root1->data != root2->data) return false;
         
         return (isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right))|| (isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left));
    }
