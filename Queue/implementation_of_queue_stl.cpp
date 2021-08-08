#include <iostream>
#include <queue>
using namespace std;

void displayQueue(queue<int> q)
{
 int n = q.size();

 for(int i=0; i<n;i++)
 {

  cout<<q.front()<<" ";
  q.pop();
 }
 cout<<"\n";

}

int main(){

 queue<int> q1;

 //Enqueue - Pushing elements to queue
 q1.push(1);
 q1.push(2);
 q1.push(4);

 cout<<"Elements of Queue are : ";
 //display Queue
 displayQueue(q1);

 //Show front and rear of queue
 cout<<"Element at front is : "<<q1.front()<<"\n";
 cout<<"Element at rear is : "<<q1.back()<<"\n";

 //Dequeue - removing element from queue
 q1.pop();

 cout<<"Queue after pop operation : ";
 displayQueue(q1);

 //To check if queue is empty or not
 cout<<"Queue is empty or not : "<<q1.empty()<<"\n";

 //size of the queue
 cout<<"Size of the Queue is : "<<q1.size();

 return 0;

}
