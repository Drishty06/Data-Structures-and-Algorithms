// notes pg: 38-39
string printLCS(string a, string b, int m, int n)
{
  LCS(a, b, m, n);
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
        j--;
      }
      else
      {
        i--;
      }
    }
  }
  reverse(res.begin(), res.end());
  return res;
}

