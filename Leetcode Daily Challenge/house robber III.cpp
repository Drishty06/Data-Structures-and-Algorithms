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
        // my first approach was using level order traversal but then I realised that it was missing out the case like this [2, 1, 3, null, 4] where this 3 is not counted along with 4 which could have given maximum answer
       // so i went to discuss tab and realized finally that this probably cannot be done by level order traversal so took the help of other solutions
       // now this approach is based on the fact that there are 2 cases:
       // 1. if we want to include current node to sum then we can add only to previous sum (excluding prev node) as if the node just previous to current node would have been added then we cannot add current as it would trip the police alarm 🚨
      // 2. we can exclude current element
      // so for every node these 2 cases would somewhat look like this
      // 1. root + subchildren
      // 2. root's children
      // for every root we will keep on noticing which yields maximum
      // https://leetcode.com/problems/house-robber-iii/discuss/79333/Simple-C%2B%2B-solution
        int tryRob(TreeNode* root, int &robMax, int &notRobMax) {
        if (!root) return 0;
        int leftRobMax = 0, leftNotRobMax = 0, rightRobMax = 0, rightNotRobMax = 0;
        
        int leftMax = tryRob(root->left, leftRobMax, leftNotRobMax);
        int rightMax = tryRob(root->right, rightRobMax, rightNotRobMax);
        robMax = root->val + leftNotRobMax + rightNotRobMax;
        notRobMax = leftMax + rightMax;
            // cout<<root->val<<" "<<leftRobMax<<leftNotRobMax<<rightRobMax<<rightNotRobMax<<endl;
        return max(robMax, notRobMax);
    }
public:
    int rob(TreeNode* root) {
        int robMax = 0, notRobMax = 0;
        return tryRob(root, robMax, notRobMax);
    }
};
