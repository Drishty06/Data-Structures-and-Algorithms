// problem link: https://practice.geeksforgeeks.org/problems/palindrome-string0817/1

	
int isPalindrome(string str)
{
    int start=0, end=str.length()-1;
    while(start < end)
    {
        if(str[start++] != str[end--]) return 0;
        else 
        {
            if(start >= end) return 1;
        }
    }
    return 1;
}
