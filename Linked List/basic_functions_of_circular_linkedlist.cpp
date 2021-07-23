// 1. print circular linked list
// 2. insert at the beginning
// 3. insert at the end
// 4. delete head node
// 5. delete node from the end

#include <bits/stdc++.h>
using namespace std;
// structure representing node
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

// 1. printing circular linked list
void printList(Node *head)
{ 
    if(head == NULL) return;
    Node *temp = head;
    do
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    while(head != temp);
}

// 2. insert at the beginning 
// idea is to first insert the node in between 1st and 2nd node
// then we swap head and temp's data
Node *insert_begin(Node *head, int data)
{
    Node *temp = new Node(data);
    if(head == NULL) 
    {
        return temp;
    }
    temp->next = head->next;
    head->next = temp;
    swap(head->data, temp->data);
    return head;
}

// 3. insert at the end
// slight difference between 2. and 3.
Node *insert_end(Node *head, int data)
{
    Node *temp = new Node(data);
    if(head == NULL) 
    {
        temp->next = temp;
        return temp;
    }
    temp->next = head->next;
    head->next = temp;
    swap(head->data, temp->data);
    return temp;
}

// 4. deleting head node
Node *delete_head(Node *head)
{
    if(head == NULL) return NULL;
    if(head-> next == NULL)
    {
        delete(head);
        return NULL;
    }
    head->data = head->next->data;
    Node *temp = head->next;
    head->next = head->next->next;
    delete(temp);
    return head;
}

// deleting from end
Node *delete_end(Node *head)
{
    if(head == NULL) return NULL;
    if(head->next == NULL)
    {
        delete(head);
        return NULL;
    }
    Node* curr = head;
    while(curr->next->next != head)
    { 
        curr = curr->next;
    }
    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete(temp);
    return head;
}


int main()
{
    cout<<"Nodes = ";
    int n;
    cin>>n;
	cout<<"Data: "<<endl;
    int data;
    cin >> data;
    Node* head = new Node(data);
    head->next = head;
    Node* curr = head;
    for(int i = 0; i < n-1; i++){
        cin >> data;
        Node* temp = new Node(data);
        curr->next = temp;
        temp->next = head;
        curr = curr->next;
    }
    printList(head);

    // insert at the beginning
    cout<<"Data (to be inserted at the beginning): ";
    cin>>data;
    head = insert_begin(head,data);
    printList(head);
    cout<<endl;

    // insert at the end
    cout<<"Data (to be inserted at the end): ";
    cin>>data;
    head = insert_end(head,data);
    printList(head);
    cout<<endl;

    // delete from beginning
    cout<<"deleting from beginning"<<endl;
    head = delete_head(head);
    printList(head);
    cout<<endl;

    // delete from end
    cout<<"deleting from end"<<endl;
    head = delete_end(head);
    printList(head);

    return 0;
}
