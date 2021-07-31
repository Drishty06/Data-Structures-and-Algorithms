
    // problem link: https://practice.geeksforgeeks.org/problems/swap-all-odd-and-even-bits-1587115621/1/?track=P100-Bit%20Magic&batchId=197
    // approach: expression len = (int)(log2(n)+1) gives the numbers of bits required to represent that number
    // if len is odd than we add 1 to it since we need to swap pairs so we need even number
    // now we compare two consecutive bits in one iteration and if they are different, we toggle them
    
    
    int toggleBit(int n, int k)
    {
        return (n ^ (1 << (k - 1)));
    }
    
    int printKthBit(unsigned int n, unsigned int k)
    {
        return ((n & (1 << (k - 1))) >> (k - 1));
    }
    unsigned int swapBits(unsigned int n)
    {
    	int len;
    	if(n % 2 == 0) len = (int)(log2(n)+1);
    	else len = (int)(log2(n)+1) +1;
    	for(int i=1; i<=len; i+=2)
    	{
    	    if(printKthBit(n, i) != printKthBit(n, i+1))
    	    {
    	        n = toggleBit(n, i);
    	        n = toggleBit(n, i+1);
    	    }
    	}
    	return n;
    }
