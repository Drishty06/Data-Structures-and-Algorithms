// problem link: https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

// middle element of linked list
// works on the concept that we keep two pointers slow and fast
// slow pointer moves one position and fast pointer moves 2 positions
// when fast reaches last position, slow would have reached the middle and in this way we get the middle element
// even number of nodes and odd number of nodes have slightly different approach

int getMiddle(Node *head)
{
   Node *slow=head;
	Node *fast=head;
	while(fast != NULL && fast -> next != NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return (slow -> data);
}
