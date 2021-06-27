// subarray with given sum using hashing
bool subArrayExists(int arr[], int n, int x) // x -> given sum
    {
       unordered_set <int> s;
       long int sum=0;
       for(int i=0; i<n; i++)
       {
           sum+=arr[i];  // using prefix sum technique along with hashing
           if(s.find(sum-x) != s.end()) // if the sum is previously seen that it means that the elements added nullified each other and sum is zero
           {
               return true;
           }
           if(sum == x)
           {
               return true;
           }
           s.insert(sum);
       }
       return false; 
    }
