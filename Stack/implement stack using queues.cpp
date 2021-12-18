// https://www.youtube.com/watch?v=jDZQKzEtbYQ
    queue<int> helperQueue;
    MyStack() {
        
    }
    
    void push(int x) {
        int size = helperQueue.size();
        helperQueue.push(x);
        for(int i=0; i<size; i++)
        {
            int poppedElement = helperQueue.front();
            helperQueue.pop();
            helperQueue.push(poppedElement);
        }
        return;
    }
    
    int pop() {
        int poppedElement = helperQueue.front();
        helperQueue.pop();
        return poppedElement;
    }
    
    int top() {
        return helperQueue.front();
    }
    
    bool empty() {
        return (helperQueue.empty());
    }
