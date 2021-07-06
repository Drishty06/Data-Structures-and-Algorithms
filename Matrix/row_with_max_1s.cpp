// problem link: https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // hint = take full adavantage of rows being sorted
	    // if we find first index of 1 in a row we can calculate total 1's
	    // we start from the top-right index and traverse left in case its a 1 and down in case its a 0
	    int row=arr.size(), col=arr[0].size();
	    int i=0, j=col-1, count=0;
	    int maxi=0 ,ans=-1;
	    while(i <= row-1 && j >= 0)
	    {
	        if(arr[i][j] == 1)
	        {
	            j--;
	            count++;
	        }
	        else
	        {
	            if(count > maxi)
	            {
    	            maxi=max(maxi, count);
    	            ans=i;
	            }
	            i++;
	        }
	    }
	    // incase our first row has all ones -> for such cases
	    if(count > maxi)
	    {
	        ans=i;
	    }
	    return ans;
	    
	}
