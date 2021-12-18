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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return head;

		ListNode *dummy = new ListNode(0);
		ListNode *prev = dummy, *curr = head, *next;

		while(curr){
			next = curr->next;
			while(prev->next && prev->next->val < curr -> val) prev = prev -> next;

			curr->next = prev->next;
			prev->next = curr;
            
			curr = next;
            prev = dummy;
		}
		return dummy->next;
    }
