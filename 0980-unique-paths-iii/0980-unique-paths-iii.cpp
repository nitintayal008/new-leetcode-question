class Solution 
{
private:
    void fn(int i, int j, int N, int M, vector<vector<int>>& grid, vector<vector<int>>& isVis, int& soln)
    {
        // After reaching the end-point
        if (grid[i][j] == 2) 
        {
            // Checking if all non-obstacle elements of grid are visited
            for (int l = 0; l < N; l++) 
                for (int m = 0; m < M; m++)
                    if ( (isVis[l][m] == 0) && (grid[l][m] != -1) )
                        return;
            
            soln++;
            return;
        } 
        // Recursive traversal for all possible moves
        if ( (i + 1 != N) && (grid[i + 1][j] != -1) && (isVis[i + 1][j] != 1) )
        {
            isVis[i + 1][j] = 1; 
            fn(i + 1, j, N, M, grid, isVis, soln);
            isVis[i + 1][j] = 0;
        }

        if ( (i - 1 >= 0) && (grid[i - 1][j] != -1) && (isVis[i - 1][j] != 1) )
        {
            isVis[i - 1][j] = 1; 
            fn(i - 1, j, N, M, grid, isVis, soln);
            isVis[i - 1][j] = 0;
        }
        
        if ( (j + 1 != M) && (grid[i][j + 1] != -1) && (isVis[i][j + 1] != 1) )
        {
            isVis[i][j + 1] = 1; 
            fn(i, j + 1, N, M, grid, isVis, soln);
            isVis[i][j + 1] = 0;
        }

        if ( (j - 1 >= 0) && (grid[i][j - 1] != -1) && (isVis[i][j - 1] != 1) )
        {
            isVis[i][j - 1] = 1; 
            fn(i, j - 1, N, M, grid, isVis, soln);
            isVis[i][j - 1] = 0;
        }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int N = grid.size(), M = grid[0].size(), soln = 0;

        vector<vector<int>> isVis(N, vector<int>(M, 0));
        
        // Starting our Unique path hunt from the starting point
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < M; j++)
                if (grid[i][j] == 1)
                    isVis[i][j] = 1, fn(i, j, N, M, grid, isVis, soln);
        return soln;
    }
};