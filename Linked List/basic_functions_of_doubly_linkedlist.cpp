// 1. insert at the beginning of Doubly linked list
// 2. insert at the end of Doubly linked list
// 3. delete head node
// 4. delete last node

#include <bits/stdc++.h>
using namespace std;

// structure representing Node
struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

// 1. insert at the beginning
Node *insert_begin(Node *head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    if(head != NULL) head -> prev = temp;
    return temp; // returning new head     
}

// 2. insert at the end
Node *insert_end(Node* head, int data)
{
    Node *temp = new Node(data);
    if(head == NULL) return temp;
    Node *curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr; 
    return head;
}

// 3. delete head node
Node *delete_head(Node* head)
{
    if(head == NULL) return NULL;
    if(head->next == NULL)
    {
        delete(head);
        return NULL;
    }
    Node *temp = head->next;
    temp->prev = NULL;
    delete(head);
    return temp;
}

// 4. delete last node
Node *delete_end(Node *head)
{
    if(head == NULL) return NULL;
    if(head->next == NULL)
    {
        delete(head);
        return NULL;
    }
    Node *curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->prev->next = NULL;
    delete(curr);
    return head;
}

void printList(Node* head)
{
    Node *curr = head;
    while(curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}



int main()
{
    cout<<"Nodes = ";
    int n;
    cin>>n;
	cout<<"Data: "<<endl;
    int data;
    cin>>data;
    Node* head = new Node(data);
    Node* tail = head;
    for(int i=0; i<n-1; i++)
	{
        cin>>data;
        Node* temp = new Node(data);
        tail -> next = temp;
        tail = tail -> next;
    }
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
