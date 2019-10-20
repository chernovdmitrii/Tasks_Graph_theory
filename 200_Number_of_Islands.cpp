//https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size(); 
        int m, k = 0; 
        if (n){
            m = grid[0].size(); 
        } else {
            m = 0; 
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    k++;
                    zeroing(grid, i, j);
                }
            }
        }
        return k;
    }

    void zeroing(vector<vector<char>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (i < 0 || j < 0 || i == n || j == m || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        zeroing(grid, i + 1, j);
        zeroing(grid, i, j + 1);
        zeroing(grid, i - 1, j );
        zeroing(grid, i, j - 1);
    }
};
