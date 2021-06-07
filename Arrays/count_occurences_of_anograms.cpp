// problem link: https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1/?category[]=sliding-window&category[]=sliding-window&difficulty[]=0&page=1&sortBy=submissions&query=category[]sliding-windowdifficulty[]0page1sortBysubmissionscategory[]sliding-window#
// window sliding technique
// almost similar to permutations in string problem

	int search(string s1, string s2) 
	{
        int count[256]={0}, window[256]={0},ans=0;
        int len1=s1.length();
        int len2=s2.length();
        for(int i=0; i<len1; i++)
        {
            count[s1[i]]++;
            window[s2[i]]++;
        }
        for(int k=len1; k<=len2; k++)
        {
            for(int j=0; j<256; j++)
            {
                if(count[j] != window[j])
                {
                    break;
                }
                else 
                {
                    if(j == 255)
                    {
                        ans++;
                    }
                }
            }
            window[s2[k]]++;
            window[s2[k-len1]]--;
        }
         return ans;
    }
