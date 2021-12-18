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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy1 = new ListNode(0);
        ListNode *dummy2 = new ListNode(0);
        ListNode *curr1 = dummy1, *curr2 = dummy2;
        ListNode *curr = head;
        while(curr != NULL)
        {
            if(curr->val < x)
            {
                curr1->next = curr;
                curr1 = curr1->next;
            }
            else
            {
                curr2->next = curr;
                curr2 = curr2->next;
            }
            curr = curr->next;
        }
        curr1->next = dummy2->next;
        curr2->next = NULL;
        return dummy1->next;
    }
};
