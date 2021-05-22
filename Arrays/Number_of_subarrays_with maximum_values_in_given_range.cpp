//Problem link: https://practice.geeksforgeeks.org/problems/number-of-subarrays-with-maximum-values-in-given-range5949/1
//My YouTube Code Explanation video😎: https://www.youtube.com/watch?v=J1PauAVnVWI 
//Window Sliding Technique

// l< Element< r ---> King
//    Element> r ---> Villian
//    Element< l ---> Aam Janta

//Fact that will helping hand of this solution💡: Number of subarrays including last element of array
//is always equal to size of array 😁
class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
      long int start=0,end=0,ans=0,empire=0
       for(int end=0; end<n; end++)
       {
           if(arr[end]>=l && arr[end]<=r)
           { // king
               empire=end-start+1;
           }
           
           if(arr[end]>r)
           { // villain
               empire=0; // king ka empire tut gaya 
               start=end+1; // naya empire
           }
           ans = ans + empire;
       }
      return ans;
    }
};

