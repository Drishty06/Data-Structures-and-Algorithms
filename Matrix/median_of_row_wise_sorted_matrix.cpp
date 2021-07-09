// problem link: https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
 int smaller_elements(vector<int> &arr, int mid)
    {
        int start=0, end=arr.size()-1;
        while(start <= end)
        {
            int mid_of_row = (start+end)/2;
            
        }
        return start;
    }
    int median(vector<vector<int>> &matrix, int n, int m)
    {
        // minimum value of the whole matrix will definitely lie in th 1st column 
        // and maximum value will lie in the last column since the rows are sorted
        // by running for loop we calculate the minimum and maximum elements of the matrix
        // other we can also use low as 1 and high as 2001 since the constraints in the que were like 1=< matrix[i][j] <= 2000
        // after knowing low and high we define a search space where our answer can lie and we are good to we with binary search
        // the idea is that for a number to be a median there should be exactly n/2 members smaller than it
        int low = 1;
        int high = 2001;
        while(low <= high)
        {
            int mid = (low+high)/2;
            int count = 0;
            for(int i=0; i<n; i++) // after calculating the mid with count the elements smaller than the mid
            {
                count += smaller_elements(matrix[i], mid); // for the same we use binary search as well
            }
            
            int total_elements = n*m;
            if(count > total_elements/2) high = mid-1;
            else low = mid+1;
        }
        
        return low;
    }
