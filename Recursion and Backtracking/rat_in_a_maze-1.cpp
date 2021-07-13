    // problem link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
    // as we want lexicographic https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
    // naive way could be making 4 if statements
    // efficient way by take u forward is by two arrays which define positions of x and y
    // strings, move in this order: down, left, right, up
    public:
    void path_generator(int i, int j, vector<vector<int>> &m, int n, string str, vector<string> &res, int directionX[], int directionY[], vector<vector<int>> &visited)
    {
		
        if(i == n-1 && j == n-1)
        {
            //cout<<str<<endl;
            res.push_back(str);
            return;
        }
        string helper = "DLRU";
        for(int index=0; index<4; index++)
        {
            int x = i+directionX[index];
            int y = j+directionY[index];
            
            if(x < n && x >= 0 && m[x][y] == 1 && visited[x][y] == 0 && y < n && y >= 0)
            {
                visited[i][j] = 1;
                path_generator(x, y, m, n, str+helper[index], res, directionX, directionY, visited);
                visited[i][j] = 0; // after returning we want the visited array to behave the same as earlier 
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        vector<vector<int>> visited(n, vector<int>(n, 0)); // intializing a 2D vector with 0
        vector <string> res;
        int directionX[4] = {1, 0, 0, -1}; 
        int directionY[4] = {0, -1, 1, 0};
        int x=0, y=0;
        if(m[0][0] != 0) path_generator(0, 0, m, n, "", res, directionX, directionY, visited);
        return res;
    }
