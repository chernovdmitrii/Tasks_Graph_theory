//https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        vector<int> _rows = {-1, 0, 1, 0};
        vector<int> _columns = {0, 1, 0, -1};
        int rows = grid.size();
        int columns = grid[0].size();
        int result = 0;

        //Scaning
        queue<int> q; 
        map<int, int> depth; //position -  depth

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (grid[i][j] == 2) {
                    q.push(i * columns + j);
                    depth.insert(make_pair(i * columns + j, 0));
                }
            }
        }
        //moving
        int minimumMoving = 0;
        int position, roww, coll;
        while (!q.empty()) {
            position = q.front();
            q.pop();
            roww = position / columns;
            coll = position % columns;
            for (int i = 0; i < 4; ++i) {
                int new_row = roww + _rows[i];
                int new_col = coll + _columns[i];
                if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < columns && grid[new_row][new_col] == 1) {
                    grid[new_row][new_col] = 2;
                    int new_pos = new_row * columns + new_col;
                    q.push(new_pos);
                    depth.insert(
                            make_pair(new_pos, depth.find(position)->second + 1));
                    result = depth.find(new_pos)->second;
                }
            }

        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return result;
    }
};
