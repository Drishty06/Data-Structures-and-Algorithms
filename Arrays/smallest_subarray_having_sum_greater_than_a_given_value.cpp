// Problem link: https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1
// My YouTube Code Explanation video😎: https://www.youtube.com/watch?v=WI8886xXRlU

int sb(int arr[], int n, int x)
    {
        int sum=0,start=0,len=n;
        for(int i=0; i<n; i++)
        {
            sum=sum+arr[i];
            while(sum > x)
            {
                len=min(len, i-start+1);
                sum=sum-arr[start]; // sliding window technique
                start++;
            }
        }
        return len;
    }
