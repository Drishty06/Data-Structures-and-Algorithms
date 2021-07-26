// problem  link: https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1#

long long  multiplyTwoLists (Node* l1, Node* l2)
{
    Node *curr1 = l1;
    Node *curr2 = l2;
    long long int first=0, second=0;
    
    while(curr1 != NULL || curr2 != NULL)
    {
        if(curr1 != NULL)
        {
            first = (first*10)%1000000007 + curr1->data;
            curr1 = curr1->next;
        }
        
        if(curr2 != NULL)
        {
            second = (second*10)%1000000007 + curr2->data;
            curr2 = curr2->next;
        }
    }
    long long int ans = ((first%1000000007) * (second%1000000007) ) %1000000007;
}
