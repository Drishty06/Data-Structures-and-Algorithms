// problem link: https://leetcode.com/problems/n-queens/
    bool safe(int n, vector<string> &helper, int row, int col) // checks whether placing the queen at current position is violating rules or not
    {
        for(int i=row-1; i>=0; i--) // checks for vertical direction
        {
            if(helper[i][col] == 'Q') return false;
        }
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++) // checks for diagonal way1
        {
            if(helper[i][j] == 'Q') return false;
        }
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) // checks for diagonal way2
        {
            if(helper[i][j] == 'Q') return false;
        }
        return true;
    }
    void QueenPosition(int n,vector<vector<string>> &res, vector<string> &helper, int row)
    {
        if(row == n) // base case
        {
            res.push_back(helper);
            return;
        }
        for(int col=0; col<n; col++) // calling the recursive function for each row and then for respective rows, checking for each columns through the loop
        {
            if(safe(n, helper, row, col)) // checks if placing a queen is violating the rules or not
            {
                helper[row][col] = 'Q'; // setting it to Q
                QueenPosition(n, res, helper, row+1); // calling for next row
                helper[row][col] = '.'; // backtracking
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> res; 
        vector<string> helper(n, std::string(n, '.')); // initializing all the elements with .... 
        QueenPosition(n, res, helper, 0);
        return res;
    }
