int countDistinct(int arr[], int n)
{
  unordered_set <int> s;
  for(int i=0; i<n; i++)
  {
    s.insert(arr[i]); // set has a property that only unique elements add up to set other similar elements are simply ignored
  }
  return s.size();
}
