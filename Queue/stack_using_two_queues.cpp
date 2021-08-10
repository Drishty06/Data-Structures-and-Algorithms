// overview: stack follows LIFO and queues follow FIFO
// for stacks: insertion : at the end and deletion : at the end
// for queues: insertion : at the end and deletion : from the front
// so to implement stacks using queue we have to somehow send this recently added item to the starting as queue removes from the front and stacks want it to be removed from the end
// so we use 2 queues and firstly we pass all current elements of quque to auxiliary queue
// now we add x to current queue
// then we again pass all the elements from auxiliary array to actual one

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
    while(q1.empty() == false)
    {
        q2.push(q1.front());
        q1.pop();
    }
    q1.push(x);
    while(q2.empty() == false)
    {
        q1.push(q2.front());
        q2.pop();
    }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    if(q1.empty()) return -1;
    int temp = q1.front();  
    q1.pop();
    return temp;
}
