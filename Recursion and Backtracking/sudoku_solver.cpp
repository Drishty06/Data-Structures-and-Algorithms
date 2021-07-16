// problem link: https://leetcode.com/problems/sudoku-solver/submissions/
    // using pepcoding hints
    
    bool isValid(vector<vector<char>>& board, int x, int y, int k)
    {
        // for row
        for(int j=0; j<9; j++)
        {
            if(board[x][j] == k+'0') return false;
        }
        // for column
        for(int i=0; i<9; i++)
        {
            if(board[i][y] == k+'0') return false;
        }
        // for sub box
        int x1=3*(x/3);
        int y1=3*(y/3);
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(board[x1+i][y1+j] == k+'0') return false;
            }
        }
        return true;
    }
    void mySudoku(vector<vector<char>>& board, vector<vector<char>>& res,  int curr_i, int curr_j)
    {
        // edge case conditions
        int row=0, col=0;
        if(curr_i == 9) 
        {
            res=board; // this line is needed, else it will always backtrack and make the element '.' and board will eventually become input only
            return;
        }
        if(curr_j == 8)
        {
            row=curr_i+1;
            col=0;
        }
        else
        {
            row=curr_i;
            col=curr_j+1;
        }
        
        if(board[curr_i][curr_j] == '.')
        {
            for(int k=1; k<=9; k++) // checking for all possible values
            {
                if(isValid(board, curr_i, curr_j, k)) // isValid checks if the row, col and subbox have k present or not
                {
                    board[curr_i][curr_j]=k+'0';
                    mySudoku(board, res, row, col);
                    board[curr_i][curr_j]='.';
                }
            }
        }
        else      
        {
            mySudoku(board, res, row, col);
        }
            
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> res;
        
        mySudoku(board, res, 0, 0);
        board=res;

    }
