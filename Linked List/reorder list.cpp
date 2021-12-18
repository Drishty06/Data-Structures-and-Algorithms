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
    
    ListNode* reverseList(ListNode* mid)
    {
        ListNode* prev = mid;
        ListNode* curr = mid->next;
        // cout<<prev->val<<curr->val<<endl;
    
        prev->next = NULL;
        while(curr != NULL)
        {
            ListNode* currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;
        }
        
        return prev;
    }
    
    ListNode* getMiddleNode(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode* start = head;
        ListNode* mid = getMiddleNode(head);
        ListNode* tail = reverseList(mid);
        // cout<<tail->val;
        
        while(tail->next != NULL)
        {
            ListNode* startNext = start->next;
            ListNode* tailNext = tail->next;
            
            start->next = tail;
            start = startNext;
            tail->next = start;
            tail = tailNext;
        }
    }
