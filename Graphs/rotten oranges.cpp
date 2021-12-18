bool isValid(int x, int y, int row, int col, vector<vector<int>> &grid)
    {
        if(x>=0 && x<row && y>=0 && y<col && grid[x][y] == 1) return true;
        return false;
    }
        
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int freshOranges = 0, timer = -1;
        queue<pair<int, int>> q;
        vector<int> Xdirection = {0, 0, -1, 1};
        vector<int> Ydirection = {-1, 1, 0, 0};
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
                if(grid[i][j] == 1)
                {
                    freshOranges++; 
                }
            }
        }
        if(q.size() == 0 && freshOranges == 0) return 0;
        if(q.size() == 0) return -1;
        
        while(! q.empty())
        {
            int rottenOrangesAtCurrLevel = q.size();
            for(int i=0; i<rottenOrangesAtCurrLevel; i++)
            {
                for(int j=0; j<4; j++)
                {
                    int x = q.front().first + Xdirection[j];
                    int y = q.front().second + Ydirection[j];
                    if(isValid(x, y, row, col, grid))
                    {
                        grid[x][y] = 2;
                        q.push({x, y});
                        freshOranges--;
                    }
                }
                q.pop();
            }
            timer++;
        }
        if(freshOranges > 0) return -1;
        return timer;
    }
