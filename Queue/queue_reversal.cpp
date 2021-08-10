// problem link: https://practice.geeksforgeeks.org/problems/queue-reversal/1
queue<int> rev(queue<int> q)
{
    queue<int> q1;
    stack<int> s;
    int len = q1.size();
    while(! q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(! s.empty())
    {
        q1.push(s.top());
        s.pop();
    }
    return q1;
    
}
