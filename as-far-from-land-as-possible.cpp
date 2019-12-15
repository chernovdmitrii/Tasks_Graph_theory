//https://leetcode.com/problems/as-far-from-land-as-possible/
class Solution {
public:
    struct Node{
        int x;
        int y;
        Node(int a, int b): x(a),y(b){}
    };
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<Node> q;
        for(int i=0; i<m; i++)
            for(int j=0; j<n;j++)
                if (grid[i][j] == 1){
                    grid[i][j] = -1;
                    q.push(Node(i, j));
                }
        
        int dist = 1;
        int level_len = q.size();
        while(!q.empty()){
            Node node = q.front();
            q.pop();
            level_len--;
            int i = node.x;
            int j = node.y;
            if (i+1<m && grid[i+1][j] == 0){
                q.push(Node(i+1, j));
                grid[i+1][j] = dist;
            }
            if (i-1>=0 && grid[i-1][j] == 0){
                q.push(Node(i-1, j));
                grid[i-1][j] = dist;
            }
            if (j+1<n && grid[i][j+1] == 0){
                q.push(Node(i, j+1));
                grid[i][j+1] = dist;
            }
            if (j-1>=0 && grid[i][j-1] == 0){
                q.push(Node(i, j-1));
                grid[i][j-1] = dist;
            }
            if (level_len == 0){
                level_len = q.size();
                dist ++;
            }
        }
        
        int max_dist = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if (grid[i][j] != -1) max_dist =  max(max_dist, grid[i][j]);
        if (max_dist == 0) max_dist = -1;
        return max_dist;
    }
};
