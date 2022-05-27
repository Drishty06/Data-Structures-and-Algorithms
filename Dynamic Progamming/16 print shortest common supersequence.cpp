// refer notes pg: 40
string printSCS(string a, string b, int m, int n)
{
  SCS(a, b, m, n);
  int i = m, j = n;
  string res;
  
  while(i > 0 && j > 0)
  {
    if(a[i - 1] == b[j - 1])
    {
      res.push_back(a[i - 1]);
      i--;
      j--;
    }
    else
    {
      if(dp[i][j - 1] > dp[i - 1][j])
      {
        res.push_back(b[j - 1]);
        j--;
      }
      else
      {
        res.push_back(a[i - 1]);
        i--;
      }
    }
  }
  
  while(i > 0) {
        res.push_back(a[i-1]);
        i--;
  }
        
  while(j > 0) {
         res.push_back(b[j-1]);
         j--;
  } 
  
  reverse(res.begin(), res.end());
  return res;
}
