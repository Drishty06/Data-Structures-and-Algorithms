// problem link:https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1#
// logic: to swap every character with every other character so as to generate all permutations
	    void per(string str,vector<string> &result, int index)
	    {
	        int n=str.length();
	        if(index == n)
	        {
	            result.push_back(str);
	            return;
	        }
	        for(int i=index; i<n; i++)
	        {
	            swap(str[index], str[i]);
	            per(str, result, index+1);
	            swap(str[index], str[i]); // backtracking to get back the original string
	        }
	    }
		vector<string>find_permutation(string str)
		{
		    vector<string> result;
		    int index=0;
		    per(str, result, 0);
		    sort(result.begin(), result.end());
		    return result;
		}
