// problem link: https://practice.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/1/?track=P100-Matrix&batchId=197

// hint: 1) Create two temporary arrays row[M] and col[N]. Initialize all values of row[] and col[] as 0.
    //       2) Traverse the input matrix mat[M][N]. If you see an entry mat[i][j] as 1, then mark row[i] and col[j] as 1.
    //       3) Traverse the input matrix mat[M][N] again. For each entry mat[i][j], check the values of row[i] and col[j]. If any of the two values (row[i] or col[j]) is 1, then mark mat[i][j] as 1. 
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        int n=matrix.size(), m=matrix[0].size();
        int row[n]={0}, col[m]={0};
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == 1)
                {
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(row[i] == 1 || col[j] == 1)
                    {
                        matrix[i][j]=1;
                    }
                }
            }
        }
    }
