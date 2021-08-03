// problem link: https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1
    
    int evaluatePostfix(string str)
    {
        stack<int> s;
        int len = str.length();
        for(int i=0; i<len; i++)
        {
            if(str[i] >= 48 && str[i] <= 57)
            {
                s.push(str[i] - 48);
            }
            else 
            {
                int op2 = s.top();
                s.pop();
                
                int op1 = s.top();
                s.pop();
                
                switch (str[i])
                {
                    case '+': s.push(op1 + op2); break;
                    case '-': s.push(op1 - op2); break;
                    case '*': s.push(op1 * op2); break;
                    case '/': s.push(op1 / op2); break;
                }
            }
        }
        return s.top();
    }
