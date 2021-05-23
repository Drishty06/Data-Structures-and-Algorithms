// problem link: https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1
// My YouTube Code Explanation video😎: https://www.youtube.com/watch?v=NwSHs6N4VRo 
// Window Sliding Technique
// elements smaller than k --> Ghar ke Log
// ghar ki size(window ki size) = Number of ghar ke log
int ghar_ke_log=0,ans=0,tracker=0;
    for(int i=0; i<n; i++) // this loop is calculating number of ghar ke log
    {
        if(arr[i] <= k)
        {
            if(arr[ghar_ke_log] > k) ans++; // this additional line is used to prepare very first window
            ghar_ke_log++;
        }                                   // ans--> bahar ke log
        
    }
    if(ghar_ke_log == 1) return 0;
    tracker = ans;
    for(int j=0; j+ghar_ke_log<n; j++)
    { // sliding window technique
       
        if(arr[j] > k) tracker--; // checking if initial window element was ghar ke log or bahar ke log?
        if(arr[j+ghar_ke_log] > k) tracker++; //checking if element to be added to window is ghar ke log or bahar ke log
         ans=min(ans, tracker);
    }
    return ans;
}
