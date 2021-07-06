// problem link: https://leetcode.com/problems/rotate-image/
void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for(int i=0; i<size; i++)
        {
            for(int j=i+1; j<size; j++)
            {
                swap(matrix[i][j], matrix[j][i]); // transpose of matrix
            }
        }
        for(int i=0; i<size; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end()); // reversing every row one by one
        }
    }
