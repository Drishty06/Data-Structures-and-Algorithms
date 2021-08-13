// problem link: https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1#
// push: simply pushing the element in o(1)
// pop: if both are empty we return -1
//      if s2 is empty then we transfer all the elements from s1 to s2 and then return top of s2 since elements in s2 will now be in reversed order
//      now after we transferred all elements from s1 to s2, now we have to simply pop the element from s2 until its empty since element are stored in reversed order
//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x)
{
    s1.push(x);
    return;
}

//Function to pop an element from queue by using 2 stacks.

int StackQueue :: pop()

{
    if(s1.empty() && s2.empty())  return -1;
    
    if(s2.empty())
    {
        while(s1.empty() == false)
        {
            s2.push(s1.top());
            s1.pop();
        }
        
    }
    int temp = s2.top();
        s2.pop();
        return temp;
}
