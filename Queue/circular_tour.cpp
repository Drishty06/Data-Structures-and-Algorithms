// problem link: https://practice.geeksforgeeks.org/problems/circular-tour/1#
    // method 3: most efficient
    
    // if current petrol pump becomes negaitve than none of its previous petrol pump can be an answer
    // reason is that if we select any element before it an consider as an answer then one thing is for sure that it will be poitiveand 
    // secondly we substract positive from a poistive then of course it will be less than current petrol
    // curr_petrol = petrol required to reach from starting to current position
    
    int tour(petrolPump p[],int n)
    {
        int start = 0;
        int curr_petrol = 0, prev_petrol = 0;
        for(int i=0; i<n; i++)
        {
            curr_petrol += p[i].petrol - p[i].distance;
            if(curr_petrol < 0)
            {
                prev_petrol += curr_petrol;
                start = i+1;
                curr_petrol = 0;
            }
        }
        
        if((curr_petrol + prev_petrol) > 0) return start;
        return -1;
    }
};
    //the complete circle without exhausting its petrol in between.
    
    // naive solution
    // time complexity: O(n^2)
    // space complexity: O(1)
    // int tour(petrolPump p[],int n)
    // {
    //   for(int i=0; i<n; i++)
    //   {
    //       int curr_petrol = 0;
    //       int end = i;
    //       while(1)
    //       {
    //           curr_petrol += p[end].petrol - p[end].distance;
    //           if(curr_petrol < 0)
    //           {
    //               break;
    //           }
    //           end = (end+1)%n;
    //           if(end == i) return i;
    //       }
    //   }
    //   return -1;
    // }
    
    // method 2:
    // time complexity: o(n)
    // space complexity: o(n)
    // idea: keep adding items in the deqeue till the curr_petrol >= 0
    // if we encounter a situation where curr-petrol < 0 then in that case, then we remove items from the deque till it is less than zero
    
    
