int setbit(int n, int k) 
{ 
    return (n | (1 << (k - 1))); 
} 
  
int clearbit(int n, int k) 
{ 
    return (n & (~(1 << (k - 1)))); 
} 
int getbit(long long int n, long long int k) 
{ 
    return (n >> k) & 1; 
} 
int updatebit(long long int n, long long int k, long long int value) 
{ 
    long long int temp=~(1<<k);
    n=n&temp;
    return (n | (value << k)); 
} 
