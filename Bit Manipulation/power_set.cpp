// problem link: https://practice.geeksforgeeks.org/problems/power-set4302/1
	// logic: using bitwise manipulation
	// example: s = abc
	// number of subsets = 2^(length of string)
	// counter   | counter | subset |
	// (decimal) | (binary)|        |
	//     0     |   000   |   ""   |
	//     1     |   001   |   "a"  | // whichever bit is set, we include that corresponding string element into our subset
	//     2     |   010   |   "b"  |
	//     3     |   011   |   "ab" |
	//     4     |   100   |   "c"  |
	//     5     |   101   |   "ac" |
	//     6     |   110   |   "bc" |
	//     7     |   111   |   "abc"|
	
		vector<string> AllPossibleStrings(string s)
		{
		    vector<string> ans;
		    int len = s.length();
		    int subset = pow(2, len);
		    
		    for(int i=0; i<subset; i++)
		    {
		        string str = "";
		        for(int j=0; j<len; j++)
		        {
		            if((i & (1<<j)) != 0) str = str + s[j];
		        }
		        if(str.length() >= 1) ans.push_back(str);
		    }
		    sort(ans.begin(), ans.end());
		    return ans;
		}
