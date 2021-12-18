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
    ListNode* merge(ListNode *head1, ListNode *head2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(head1 != NULL && head2 != NULL)
        {
            if(head1->val > head2->val)
            {
                curr->next = head2;
                head2 = head2->next;
            }
            else
            {
                curr->next = head1;
                head1 = head1->next;
            }
		    curr = curr->next;
        }
        if(head1) curr->next = head1;
        if(head2) curr->next = head2;
        
        return dummy->next;
    }

ListNode* mergeSortForLL(ListNode *head)
{
    if(head == NULL || head->next == NULL) return head;
    
    ListNode* slow = head; 
    ListNode* fast = head->next;
    
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
       
    }
     
    ListNode* newHead = slow->next;
    slow->next = NULL;
    return merge(mergeSortForLL(head), mergeSortForLL(newHead));
}
    
ListNode* sortList(ListNode* head) {
	return mergeSortForLL(head); 
 }

};
