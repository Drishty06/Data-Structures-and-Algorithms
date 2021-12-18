// https://www.youtube.com/watch?v=3Et9MrMc02A 
    stack<int> mainStack;
    stack<int> helperStack;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(! mainStack.empty())
        {
            int temp = mainStack.top();
            mainStack.pop();
            helperStack.push(temp);
        }
        mainStack.push(x);
        while(! helperStack.empty())
        {
            int temp = helperStack.top();
            helperStack.pop();
            mainStack.push(temp);
        }
    }
    
    int pop() {
        int poppedElement = mainStack.top();
        mainStack.pop();
        return poppedElement;
    }
    
    int peek() {
        return mainStack.top();
    }
    
    bool empty() {
        return mainStack.empty();
    }
