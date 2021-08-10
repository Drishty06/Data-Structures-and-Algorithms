#include<bits/stdc++.h> 
using namespace std;
// class representing a tree node
class Node {
    public:
    int data;
    Node *next;
    Node *prev;
    
    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};
// function to create a new node
Node* newNode(int x) {
    Node *node = new Node(x);
    return node;
}
// front points to start of Deque and rear points to the end of Deque
Node *front = NULL;
Node *rear = NULL;
// Variable representing size of Deque
int Size = 0;
void insertFront(int x) {
    // Create a new Node with required parameters
    Node *node = newNode(x);
    if (front == NULL) {
        // This is the first node to be inserted
        front = rear = node;
    } else {
        // Add the node before front
        node->next = front;
        front->prev = node;
        // update front
        front = node;
    }
    // Increment size
    Size++;
}
void insertEnd(int x) {
    // Create a new Node with required parameters
    Node *node = newNode(x);
    if (rear == NULL) {
        // This is the first node to be inserted
        front = rear = node;
    } else {
        // Insert the node after rear
        node->prev = rear;
        rear->next = node;
        // update rear
        rear = node;
    }
    // Increment size
    Size++;
}
void deleteFront() {
    if (front == NULL) {
        // no node to delete
        return;
    }
    if (front == rear) {
        // only 1 node is present
        front = rear = NULL;
    } else {
        // delete front and move front ahead
        Node *temp = front;
        front = front->next;
        front->prev = NULL;
        // deallocate the memory taken by temp
        delete(temp);
    }
    // Decrement size
    Size--;
}
void deleteEnd() {
    if (rear == NULL) {
        // no node to delete
        return;
    }
    if (front == rear) {
        // only 1 node is present
        front = rear = NULL;
    } else {
        // delete rear and move rear backwards
        Node *temp = rear;
        rear = rear->prev;
        rear->next = NULL;
        // deallocate the memory taken by temp
        delete(temp);
    }
    // Decrement size
    Size--;
}
int getFront() {
    if (front != NULL) {
        return front->data;
    }
    return -1;
}
int getEnd() {
    if (rear != NULL) {
        return rear->data;
    }
    return -1;
}
int size() {
    return Size;
}
bool isEmpty() {
    if (front == NULL) {
        return true;
    }
    return false;
}
void erase() {
    // mark rear as null
    rear = NULL;
    // traverse the doubly linked list
    while (front != NULL) {
        Node *temp = front;
        // delete all the prev pointers
        front->prev = NULL;
        front = front->next;
        // Deallocate the memory taken by temp
        delete(temp);
    }
    // Set size as 0
    Size = 0;
}
int main() {
    // Example
    insertFront(5);                 // 5
    insertEnd(10);                  // 5 <-> 10
    insertEnd(11);                  // 5 <-> 10 <-> 11
    insertFront(19);                // 19 <-> 5 <-> 10 <-> 11
    cout<<getFront()<<endl;
    cout<<getEnd()<<endl;
    deleteEnd();                    // 19 <-> 5 <-> 10
    cout<<getEnd()<<endl;
    deleteFront();                  // 5 <-> 10
    cout<<getFront()<<endl;     
    cout<<size()<<endl;
    if (isEmpty()) {
        cout<<"true"<<endl;
    } else {
        cout<<"false"<<endl;
    }
    erase();
    if (isEmpty()) {
        cout<<"true"<<endl;
    } else {
        cout<<"false"<<endl;
    }
    
    return 0;
}
