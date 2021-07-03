// problem link: https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1/?category[]=sliding-window#
    // hint: Iterate over the array while storing sum of prefix covered and the remainder when that sum is divided by k.
    // Store the index at which a particular remainder is found in a hashmap.

	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    unordered_map <int, int> mp; // this map stores remainder of prefix sum as key and its index as its value
	    long int sum=0, rem, len, best=0;
	    for(int i=0; i<n; i++)
	    {
	        sum += arr[i]; // prefix sum
	        rem = ((sum % k)+k)%k; // as the sum can be negative so taking modulo twice
	        if(rem != 0) 
	        {
    	        if(mp.find(rem) != mp.end())
    	        {
    	            len = i-mp.find(rem)->second;
    	            best = max(best, len);
    	        }

	        }
	        else // if remainder is equal to zero it means all array elements till that position is a possible sub array
	        {
	            len = i+1;
	            best = max(best, len);
	        }

	        mp.insert({rem, i});
	    }
	    return best;
	}
