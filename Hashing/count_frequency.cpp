void countfreq(int arr[], int n)
{
  unordered_map <int, int> mp;
  for(int i=0; i<n; i++)
  {
    mp[arr[i]]++; // if arr[i] is seen for the first time then it creates new key and value else it simply increments
  }
  for(auto x: mp)
  {
    cout<<x.first<<" "<<x.second<<endl;
  }
}
