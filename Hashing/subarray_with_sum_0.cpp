// subarray with 0 sum
// problem link: https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
bool subArrayExists(int arr[], int n)
    {
       unordered_set <int> s;
       long int sum=0;
       for(int i=0; i<n; i++)
       {
           sum+=arr[i];  // using prefix sum technique along with hashing
           if(s.find(sum) != s.end()) // if the sum is previously seen that it means that the elements added nullified each other and sum is zero
           {
               return true;
               
           }
           if(sum == 0)
           {
               return true;
           }
           s.insert(sum);
       }
       return false; 
    }
