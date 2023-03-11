/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    
    ListNode* getMiddleNode(ListNode* node, ListNode* nextToEndNode) {
        ListNode* slow = node;
        ListNode* fast = node;

        while(fast != nextToEndNode && fast->next != nextToEndNode) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    TreeNode* LLtoBST(ListNode* node, ListNode* nextToEndNode) {
        if(node == nextToEndNode) return NULL;

        ListNode* midNode = getMiddleNode(node, nextToEndNode);
        TreeNode* root = new TreeNode(midNode->val);

        root->left = LLtoBST(node, midNode);
        root->right = LLtoBST(midNode->next, nextToEndNode);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return LLtoBST(head, NULL);
    }
};
