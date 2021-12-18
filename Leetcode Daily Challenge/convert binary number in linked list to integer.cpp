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
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* curr = head;
        int decimal = 0, i = 0;
        int totalElements = -1;
        while(curr != NULL)
        {
            curr = curr->next;
            totalElements++;
        }
        curr = head;
        while(curr != NULL)
        {
            decimal += ((curr->val) * (pow(2, totalElements)));
            totalElements--;
            curr = curr->next;
        }
        return decimal;
    }
};
