// problem link: https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1
  // logic: number of set bits will be one only if it is a power of two
  // so we used the same logic as that of power of two
  // now we had to return the position, so for that this expression (int)(log2(n)+1) basically returns the numbers of bits required to represent this number and since this 1 will be then present at the very first position therefore this is the answer
    int findPosition(int n) {
        
        if(n == 0) return -1;
        if((n & (n-1)) == 0) return (int)(log2(n)+1);
        return -1;
    }
