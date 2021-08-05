 // problem link: https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
    
    vector <int> calculateSpan(int price[], int n)
    {
       vector <int> vec;
       stack<int> s;
       s.push(0);
       vec.push_back(1);
       for(int i=1; i<n; i++)
       {
           while(s.empty() == false && price[s.top()] <= price[i]) s.pop();
           int span;
           if(s.empty()) span = i+1;
           else span = (i - s.top());
           vec.push_back(span);
           s.push(i);
       }
       return vec;
    }
