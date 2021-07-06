// problem link: https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1#

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> matrix) {
        
        int ans[N*N], count=0;
        
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
               ans[count]=matrix[i][j];
               count++;
            }
        }
       
        count=0;
        sort(ans, ans+N*N);
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
               matrix[i][j]=ans[count];
               count++;
            }
        }
        return matrix;
    }
