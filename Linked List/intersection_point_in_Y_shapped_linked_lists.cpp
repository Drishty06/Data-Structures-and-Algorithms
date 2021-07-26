// problem link: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1#

// idea :
// eg: list1 = 4 1|8 4 5
//     list2 = 5 6 1|8 4 5
// to reach the common point (here 8) list 1 has to travel 2 nodes and list2 has to travel 3 nodes
// now if any of the lists reaches end then we divert it to the head of the next node
// in this way both will reach the common point at the same time
// 4 1 8 4 5->5 6 1 | 8 4 5
// 5 6 1 8 4 5->4 1 | 8 4 5
// this way they meet at the same point

int intersectPoint(Node* head1, Node* head2)
{
    Node *curr1 = head1;
    Node *curr2 = head2;
    while(curr1 != curr2)
    {
        curr1 = curr1 == NULL? head2 : curr1->next;
        curr2 = curr2 == NULL? head1 : curr2->next;
    }
    return curr1->data;

}

