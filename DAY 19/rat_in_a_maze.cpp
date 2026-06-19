class Solution {
public:
    vector<string> result;
    void path(vector<vector<int>> &m, int x, int y, string dir, int n) {
        if (x == n - 1 && y == n - 1) {
            result.push_back(dir);
            return;
        }
        m[x][y] = 0;   
        if (x > 0 && m[x - 1][y] == 1)
            path(m, x - 1, y, dir + 'U', n);
        if (y > 0 && m[x][y - 1] == 1)
            path(m, x, y - 1, dir + 'L', n);
        if (x < n - 1 && m[x + 1][y] == 1)
            path(m, x + 1, y, dir + 'D', n);
        if (y < n - 1 && m[x][y + 1] == 1)
            path(m, x, y + 1, dir + 'R', n);
        m[x][y] = 1;   
    }
    vector<string> findPath(vector<vector<int>> &grid) {
        int n = grid.size();
        result.clear();
        if (grid[0][0] == 0 || grid[n - 1][n - 1] == 0)
            return result;
        path(grid, 0, 0, "", n);
        sort(result.begin(), result.end());
        return result;
    }
};