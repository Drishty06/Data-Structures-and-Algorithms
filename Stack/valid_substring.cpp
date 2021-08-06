 // problem link: https://practice.geeksforgeeks.org/problems/valid-substring0624/1#
  // firstly initialize the stack eith -1 in it
  // now if it is an opening bracket, we simply push the index of it
  // else if it is a closing bracket then we check if the stack is empty, if it is empty then we update the value of length of string
  // else we simply push the index
    int findMaxLen(string str) {
        stack<int> s;
        s.push(-1);
        int len = str.length(), curr = 0, res = 0;
        for(int i=0; i<len; i++)
        {
            if(str[i] == '(') s.push(i);
            else
            {
                s.pop();
                if(s.empty() == false)
                {
                    curr = i-s.top();
                    res = max(res, curr); 
                }
                else
                {
                    s.push(i);
                }
            }
        }
        return res;
    }
