// problem link: https://practice.geeksforgeeks.org/problems/set-bits0143/1#
int setBits(int n) 
    {
        int count = 0;
        
        for(int i=1; i<=(int)(log2(n)+1); i++)
        {
            if((n & (1 << (i-1))) != 0) count += 1;
        }
        return count;
    }
