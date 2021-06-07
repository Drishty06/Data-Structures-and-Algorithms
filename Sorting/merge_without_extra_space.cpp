// Problem link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#
// My YouTube Code Explanation video😎: https://www.youtube.com/watch?v=14Qrn0Irn_E

// we have two families each comprising of bachha party and bade log
// without using any extra space we need to store all bachha party in one family and bade log in the other one
// two pointer approach 
// without using any extra space, we store smaller elements in 1st array and rest in 2nd array
void merge(int family1[], int family2[], int n, int m) 
	{                     // slightly modified two pointer approach where one pointer is pointing to staring of one array and 
	     int i=0,j=n-1;   // and another pointer pointing to last element of second array
	    while(i < m && j >= 0) // we continue checking until with reach the end of any of the 2 arrays
	    {
	        if(family1[j] > family2[i]) // comparing both the arrays and checking if element of 1st array is bade log in comparision to bachha party
	        {
	            swap(family1[j], family2[i]); // if element of 1st array is greater than we swap so as to get alll smaller elements in 1st array
	        }
	        i++; // moving the two pointers furthur
	        j--;
	    }
	    sort(family1,family1+n); // Swapping may result in unorederd elements so finaaly sorting them
	    sort(family2,family2+m);
}
