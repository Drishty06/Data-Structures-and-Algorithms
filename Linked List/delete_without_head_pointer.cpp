// problem link: https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1#

    // trick: copy the data of next node to current node
    void deleteNode(Node *del)
    {
       del->data = del->next->data; // copying the data
       Node *temp = del->next;
       del->next = del->next->next;
       delete(temp);
    }
