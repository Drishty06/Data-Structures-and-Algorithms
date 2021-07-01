// problem link: https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence0534/1#
string secFrequent (string arr[], int n)
    {
       unordered_map <string, int> mp;
       int max1=0, max2=0;
       string str1="", str2="";
       // there are 3 possible cases:
       // 1. mp[arr[i]] > max1 as well mp[arr[i]] > max2 -> max2=max1, max1=cmp[arr[i]]
       // 2. mp[arr[i]] > max2 but mp[arr[i]] < max1 -> max2=mp[arr[i]]
       // also we use string variables to store the answers alongwith
       for(int i=0; i<n; i++)
       {
           mp[arr[i]]++;
           if(mp[arr[i]] > max1)
           {
               if(str1 != arr[i])
               {
                   max2 = max1;
                   str2 = str1;
               }
               max1 = mp[arr[i]];
               str1 = arr[i];
           }
           else if(mp[arr[i]] > max2 && mp[arr[i]] <= max1 && str1 != arr[i])
           {
               max2 = mp[arr[i]];
               str2 = arr[i];
           }
       }
       return str2;
    }
