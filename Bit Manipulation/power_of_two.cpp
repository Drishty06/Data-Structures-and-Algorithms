// problem link: https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1
    bool isPowerofTwo(long long n){
        
        if(n == 0) return false;
        if((n & (n-1)) == 0) return true;
        return false;
    }
