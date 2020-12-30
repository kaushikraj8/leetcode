class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0;
        int n=grid.size();
        int m=grid[0].size();
        bool rotting = true, fresh = true;
        
        while (rotting) {
            rotting = fresh = false;
            
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    if (!fresh && grid[i][j] == 1) fresh = true;
                    else if (grid[i][j] == count + 2) {
                        if (i > 0 && grid[i - 1][j] == 1)
                            rotting = grid[i - 1][j] = count + 3;
                        if (i < n - 1 && grid[i + 1][j] == 1)
                            rotting = grid[i + 1][j] = count + 3;
                        if (j > 0 && grid[i][j - 1] == 1)
                            rotting = grid[i][j - 1] = count + 3;
                        if (j < m - 1 && grid[i][j + 1] == 1)
                            rotting = grid[i][j + 1] = count + 3;
                    }
                }
            }
            
            if (rotting) count++;
        }
        return fresh ? -1 : count;
    }
};