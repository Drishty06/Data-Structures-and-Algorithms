// Problem link: https://practice.geeksforgeeks.org/problems/rank-the-permutations2323/1#
// based on finding lexicographic rank of string 
// based on the method which was used in 12th grade to find rank of given word

int fact(int n)
{
    return (n <= 1) ? 1 : n * fact(n - 1);
}


    int rank(string S){
        int len=S.length();
        int temp=fact(len);
        int sum=1;
        int num=len-1;
        for(int i=0; i<len; i++)
        {
            int count=0;
            for(int j=i+1; j<len; j++) 
            {
                if(S[j] < S[i]) count++; // fix a letter and increment the count for every element which is greater than fixed element on its right
                if(S[j] == S[i])  // 0 should be returned in case of similar characters as mentioned in question
                {
                    sum=0;
                    break;
                }
            }
            if(sum != 0)
            {
                temp=temp/(len-i); 
                sum=sum+(count*temp); // ways to arrange remaining letters which are not fixed =(unfixed letters)!
            }
            else break;
            
        }
        
    return sum%1000003;
        
    }
