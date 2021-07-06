// problem link: https://leetcode.com/problems/search-a-2d-matrix/
// method 1:

bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0; i<n; i++)
        {
            if(target >= matrix[i][0] && target <= matrix[i][m-1])
            {
                if(binary_search(matrix[i].begin(), matrix[i].end(), target))
                    return true;
            }
        }
        return false;
    }

// method 2:

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int i = 0;
        int j = cols-1;
        while(i >= 0 && j>= 0 && i < rows && j < cols)
        {
            if(matrix[i][j] == target)
            {
                return true;
            }
            else if(matrix[i][j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
