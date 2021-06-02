// problem link: https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1
// Modified two pointer approach

	long long countTriplets(long long arr[], int n, long long x)
	{
	    // eg: n = 5 x = 10 arr = 5 1 8 6 9
	    // naive way is a normal brute force with 3 loops and with time complexity O(n^3)
	    // to optimize it and complete it in O(n^2) complexity we firstly sort the array
	    long long int count=0,i,j,k,sum;
	    sort(arr, arr+n); // arr = 1 5 6 8 9 
	    // we'll be fixing one iterator i and 
	    // then we'll be using two pointer approach for j and k
	    for(i=0; i<n-2; i++)
	    {
	        // i->fixed
	        j=i+1; 
	        k=n-1;
	        
	        while(k > j)
	        {
	            // now we use 2 pointer approach until j and k meet each other
	            sum=arr[i]+arr[j]+arr[k]; // if the sum is greater than x than we decrease "k" since array is sorted
			if(sum < x)               // and if sum is less than x than we increament "j"
			{
			    count+=k-j;          // if element at kth index and jth index summing up with ith indexed element is less than x   
			    j++;                 // than obviously, the elements between jth and kth indices will be less than x since 
			}                        // the array is sorted and kth iterator now can take any index between j and current k to give desired sum
			else
			{
			    k--;
			}
	        }
	    }
	    return count;
	}
