// singly linked list
// index:
// 1. creating a linked list by: 
//    a. manually adding one by one (line: 135)
//    b. knowing the number of nodes and then taking inputs accordingly (line: 154)
// 2. printing the linked list
//    a. iterative solution (line: 35)
//    b. recursive solution (line: 46)
// 3. insertion of an element in the linked list
//    a. insertion at the beginning (line: 54)
//    b. insertion at the end (line: 62)
//    c. insertion in the middle (line: )
// 4. searching for an element in linked list
//    a. iterative solution (line: 76)
//    b. recursive solution (line: 93)
// 5. deletion of an element in linked list
//    a. deletion from beginning (line: 106)
//    b. deletion from end (line: 114)

#include <bits/stdc++.h>
using namespace std;

// structure representing nodes
struct Node
{
	int data;
	Node *next;
	Node(int x) // constructor
	{
		data=x;
		next=NULL;
	}
};

// 2. (a) iterative method to print linked list
void printList(Node *head)
{
	Node *curr = head;
	while(curr != NULL)
	{
		cout<<(curr -> data)<<" ";
		curr = curr -> next;
	}
}

// 2. (b) recursive method to print linked list
void printList_recursion(Node *head)
{
	if(head == NULL) return;
    cout<<head -> data<<" ";
    printList_recursion(head->next);
}

// 3. (a) insertion at the beginning
Node *insert_begin(Node *head, int value)
{
	Node *temp = new Node(value);
	temp -> next = head;
	return temp;
}

// 3. (b) insertion at the end
Node *insert_end(Node *head, int value)
{
	Node *temp = new Node(value);
	if(head == NULL) return temp;
	Node *curr = head;
	while(curr -> next != NULL)
	{
		curr = curr -> next;
	}
	curr -> next = temp;
	return head;
}

// 4. (a) iterative solution for searching an element in linked list
int search(Node *head, int value)
{
	Node *curr = head;
	int index = 1;
	while(curr != NULL)
	{
		if(curr -> data == value) return index;
		else
		{
			index++;
			curr = curr -> next;
		}
	}
	return -1;
}

// 4. (b) recursive solution for searching an element in linked list
int recursive_search(Node *head, int value)
{
	if(head == NULL) return -1;
	if(head -> data == value) return 1;
	else 
	{
		int result = recursive_search(head -> next, value);
		if(result == -1) return -1;
		else return (result+1);
	}
}

// 5. (a) deletion of first element from beginning
Node *delete_first(Node *head)
{
	Node *temp = head -> next;
	delete(head); // deallocating that memory
	return temp; // returning temp as the new head
}

// 5. (b) deletion of first element from end
Node *delete_last(Node *head)
{
	if(head == NULL) return NULL;
	if(head -> next == NULL) 
	{
		delete head;
		return NULL;
	}
	Node *curr = head;
	while((curr -> next -> next) != NULL)
	{
		curr = curr -> next;
	}
	delete curr -> next;
	curr -> next = NULL;
	return head;
}

int main() 
{ 
	// 1.(a) creating linked list manually
	Node *head = new Node(10);
	Node *second = new Node(20);
	Node *third = new Node(30);
	head -> next = second;
	second -> next = third;
	/* 1.(a) alternative
	Node *head = new Node(10);
	head -> next = new Node(20);
	head -> next -> next = new Node(30);
	*/
	cout<<"output for static input:"<<endl;
	cout<<"using iterative solution"<<endl;
	printList(head);
	cout<<endl;
	cout<<"using recursive solution"<<endl;
	printList_recursion(head);
	cout<<endl;

	// 1. (b) knowing the number of nodes and then taking inputs accordingly
	int n;
    cout<<"Nodes = ";
    cin>>n;
	cout<<"Data: "<<endl;
    int data;
    cin>>data;
    Node* head1 = new Node(data);
    Node* tail = head1;
    for(int i=0; i<n-1; i++)
	{
        cin>>data;
        Node* temp = new Node(data);
        tail -> next = temp;
        tail = tail -> next;
    }

	cout<<"output for manually added input:"<<endl;
	cout<<"using iterative solution"<<endl;
	printList(head1);
	cout<<endl;
	cout<<"using recursive solution"<<endl;
	printList_recursion(head1);
	cout<<endl;

	cout<<"Element to be searched in manually added input:"<<endl;
	int value;
    cin>>value;
    cout<<"using iterative solution"<<endl;
	cout<<search(head1, value)<<endl;
	cout<<"using recursive solution"<<endl;
	cout<<recursive_search(head1, value)<<endl;

	cout<<"insertion at the beginning"<<endl;
	cout<<"Value to be added at the beginning = ";
	int value1;
	cin>>value1;
	head1 = insert_begin(head1, value1);
	cout<<"Linked list after inserting at the beginning"<<endl;
	printList(head1);

	cout<<"insertion at the end"<<endl;
	cout<<"Value to be added at the end = ";
	int value2;
	cin>>value2;
	head1 = insert_end(head1, value2);
	cout<<"Linked list after inserting at the end"<<endl;
	printList(head1);

	cout<<"after deleting the first element from beginning"<<endl;
	head1 = delete_first(head1);
	printList(head1);
	cout<<"after deleting the last element"<<endl;
	head1 = delete_last(head1);
	printList(head1);

	return 0;
}
