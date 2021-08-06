 // problem link: https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#
    // we first insert all the elements from 1 to n into the stack - these are the possiblities of the persons who can be celebrity
    // then we take two elements from stack at a time
    // there are following four cases:
    //  1. arr[top][bottom] = 0 and arr[bottom][top] = 0 : person A does not know B and person B does not know A
    //  2. arr[top][bottom] = 1 and arr[bottom][top] = 1 : person A knows B and person B knows A
    //  3. arr[top][bottom] = 0 and arr[bottom][top] = 1 : person A does not know B and person B knows A, top can be a celebrity
    //  4. arr[top][bottom] = 1 and arr[bottom][top] = 0 : person A knows B and person B does not know A, bottom can be a celebrity
    // after this if stack is empty then return -1
    // if stack size 1 then in that case we check if that row has all 0s and if that column has all 1s except main diagonal elements - condition for that element to be a celebrity
    
    int celebrity(vector<vector<int> >& arr, int n) 
    {
        stack<int> s;
        for(int i=0; i<n; i++)
        {
            s.push(i);
        }
        while(s.size() >= 2)
        {
            int top = s.top();
            s.pop();
            int bottom = s.top();
            s.pop();
            if((arr[top][bottom] == 0 && arr[bottom][top] == 0) && arr[top][bottom] == 1 && arr[bottom][top] == 0) continue;
            else
            {
                if(arr[top][bottom] == 0 && arr[bottom][top] == 1) s.push(top);
                else if(arr[top][bottom] == 1 && arr[bottom][top] == 0) s.push(bottom);
            }
        }
        if(s.size() == 1) 
        {
            int top = s.top();
            s.pop();
            for(int j=0; j<n; j++)
            {
                if(arr[top][j] == 1) return -1;
                if(top != j && arr[j][top] == 0) return -1;
            }
            s.push(top);
        }
        if(s.empty() == true) return -1;
        return s.top();
        
    }
