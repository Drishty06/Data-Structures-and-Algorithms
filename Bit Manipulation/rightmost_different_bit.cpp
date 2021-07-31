
    // problem link: https://practice.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1/?track=P100-Bit%20Magic&batchId=197
    
    int posOfRightMostDiffBit(int m, int n)
    {
        int len;
        if(m > n) len = (int)(log2(m)+1);
        else len = (int)(log2(n)+1);
        for(int i=1; i<=len; i++)
        {
            if((m & (1 << (i-1))) != (n & (1 << (i-1))))
            {
                return i;
            }
        }
        return -1;
    }
