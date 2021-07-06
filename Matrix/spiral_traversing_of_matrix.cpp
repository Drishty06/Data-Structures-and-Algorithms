// problem link: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int top=0, bottom=r-1, left=0, right=c-1;
        vector <int> v;
        while(top <= bottom && left <= right)
        {
            for(int i=left; i<=right; i++) // for top row
            {
                v.push_back(matrix[top][i]);
            }
            top++;
            
            for(int i=top; i<=bottom; i++) // for right column
            {
                v.push_back(matrix[i][right]);
            }
            right--;
            
            if(top <= bottom)
            {
                for(int i=right; i>=left; i--) // for bottom row
                {
                    v.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            if(left <= right)
            {
                for(int i=bottom; i>=top; i--) // for left column
                {
                    v.push_back(matrix[i][left]);
                }
                left++;
            }
        } 
        return v;
    }
