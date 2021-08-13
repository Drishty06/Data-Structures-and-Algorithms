// problem link: https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1#
// idea:
// Use a stack to reverse the elements of list.
// Use another Queue to maintain the order of elements which are not be reversed.
// Pop first k elements from queue and push it in the stack.
// While stack is not empty, push the elements into the new queue.
// Then add rest of the elements of the original queue to the new queue.
// Return the new queue.

queue<int> modifyQueue(queue<int> q, int k)
{
    queue<int> ans;
    int n = q.size();
    stack<int> s;
    for(int i=0; i<k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while(! s.empty())
    {
        ans.push(s.top());
        s.pop();
    }
    for(int i=k; i<n; i++)
    {
        ans.push(q.front());
        q.pop();
    }
    return ans;
}
