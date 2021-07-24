// problem link: https://practice.geeksforgeeks.org/problems/find-length-of-loop/1/?track=P100-Linked%20List&batchId=197
// similar to concept used in detection and removal of loop
int countNodesinLoop(struct Node *head)
{
    Node *slow = head;
        Node *fast = head;
        // detecting the loop
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(slow != fast) return 0;
        
        int count=0;
        fast = fast->next;
        while(fast != slow)
        {
            fast = fast->next;
            count++;
        }
        return count+1;
}
