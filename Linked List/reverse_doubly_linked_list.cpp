// problem link: https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
// idea is to simply swap previous and next links
Node* reverseDLL(Node * head)
{
   if(head == NULL || head->next == NULL) return head;
   Node *curr = head;
   while(curr->next != NULL) // here if we use the condition as (curr->next != NULL) then at the last curr becomes curr->prev and therefore curr becomes null and since we are returning that has head than it will give seg fault
   {
       swap(curr->next, curr->prev);
       curr = curr->prev;
   }
   swap(curr->prev, curr->next);
   return curr;
}
