/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void withinRangeSum(TreeNode* root, int low, int high, int& sum)
    {
        if(root == NULL)
        {
            return;
        }
        int curr = root->val;
        
        if(curr >= low && curr <= high)
        {
            // cout<<curr<<endl;
            sum += curr;
            withinRangeSum(root->left, low, high, sum);
            withinRangeSum(root->right, low, high, sum);
        }
        else if(curr < low)
        {
            withinRangeSum(root->right, low, high, sum);
        }
        else if(curr > high)
        {
            withinRangeSum(root->left, low, high, sum);
        }
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        withinRangeSum(root, low, high, sum);
        return sum;
    }
