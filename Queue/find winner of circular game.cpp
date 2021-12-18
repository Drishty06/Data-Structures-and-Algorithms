int findTheWinner(int n, int k) {
        queue<int> membersQ;
        for(int i=1; i<=n; i++)
        {
            membersQ.push(i);
        }
        int count = 1;
        while(membersQ.size() != 1)
        {
            if(count == k)
            {
                // cout<<membersQ.front();
                count = 1;
                membersQ.pop();
            }
            else
            { 
                count++;
                int temp = membersQ.front();
                membersQ.pop();
                membersQ.push(temp);
            }
            
        }
        return membersQ.front();
    }
