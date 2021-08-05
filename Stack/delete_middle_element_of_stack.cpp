
    // problem link: https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1/?track=P100-Stack&batchId=197
    // using an auxiliary array, store half elements of stack into another stack and then pop the mid and place the remaining items back
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        stack<int> helper;
        int mid = sizeOfStack/2;
        for(int i=0; i<mid; i++)
        {
            helper.push(s.top());
            s.pop();
        }
        s.pop();
        for(int i=0; i<mid; i++)
        {
            s.push(helper.top());
            helper.pop();
        }
    }
