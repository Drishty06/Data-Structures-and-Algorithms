// problem link: https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
int findLongestConseqSubseq(int arr[], int n)
    {
      unordered_set <int> s;
      int ans, best=0;
      for(int i=0; i<n; i++)
      {
          s.insert(arr[i]);
      }
      for(int i=0; i<n; i++)
      {
          if(s.find(arr[i]-1) == s.end())
          {
              ans=arr[i];
              while(s.find(ans) != s.end())
              {
                  ans++;
              }
             best = max(best, ans-arr[i]);
          }
           
      }
      return best;
    }
