// problem link: https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1
    bool match(char a, char top)
    {
        if((a == ')' && top == '(') || (a == '}' && top == '{') || (a == ']' && top == '[')) return true;
        return false;
    }
    
    bool ispar(string x)
    {
        stack <int> s;
        for(int i=0; i<x.length(); i++)
        {
            // opening brackets - no worries, just insert
            if(x[i] == '(' || x[i] == '{' || x[i] == '[')
            {
                s.push(x[i]);
            }
            // closing brackets - check whether it th matching with the bracket at the top of the stack
            else 
            {
                if(s.empty() == true) return false;
                else if(match(x[i], s.top()) == false) return false;
                else s.pop();
            }
        }
        if(s.empty() == true) return true;
        return false;
    }
