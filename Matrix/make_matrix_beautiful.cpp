// problem link: https://practice.geeksforgeeks.org/problems/make-matrix-beautiful-1587115620/1/?track=P100-Matrix&batchId=197#

int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        int row[n]={0}, col[n]={0};
        int maxi=0, ans=0;
        for(int i=0; i<n; i++) // to find sum of all rows and columns
        {
            for(int j=0; j<n; j++)
            {
                row[i]+=matrix[i][j];
                col[j]+=matrix[i][j];
            }
        }
        
        for(int i=0; i<n; i++) // maximum of all rows and columns' sum
        {
            maxi=max(maxi, row[i]);
            maxi=max(maxi, col[i]);
        }
        
        for(int i=0; i<n; i++) // traversing through all diagonal elements covers all rows and columns
        {
            ans+=(2*maxi-row[i]-col[i]); // try it for one example and u will notice that the answer we get is twice the required ans since their is some overlapping of elements
        }
        
        return ans/2;
    } 
