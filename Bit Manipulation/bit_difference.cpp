// problem link: https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1#
int countBit(int n, int k)
    {
        if((n & (1 << (k-1))) != 0) return 1;
        else return 0;
    } 
    
    int countBitsFlip(int a, int b){
        
        int A = (int)(log2(a)+1);
        int B = (int)(log2(b)+1);
        int n, count = 0;
        if(A > B) n = A;
        else n = B;
        
        for(int i=1; i<=n; i++)
        {
            if(countBit(a, i) != countBit(b, i)) count += 1;
        }
        
        
        return count;
        
        
    }
