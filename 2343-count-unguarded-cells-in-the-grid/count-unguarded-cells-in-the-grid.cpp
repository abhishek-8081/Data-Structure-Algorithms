
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {

        auto marki = [&](int row, int col, vector<vector<int>>& grid) {
            for (int i = row - 1; i >= 0; i--) {
                if (grid[i][col] == 2 || grid[i][col] == 3) break;
                grid[i][col] = 1;
            }
            for (int i = row + 1; i < m; i++) {
                if (grid[i][col] == 2 || grid[i][col] == 3) break;
                grid[i][col] = 1;
            }
            for (int j = col - 1; j >= 0; j--) {
                if (grid[row][j] == 2 || grid[row][j] == 3) break;
                grid[row][j] = 1;
            }
            for (int j = col + 1; j < n; j++) {
                if (grid[row][j] == 2 || grid[row][j] == 3) break;
                grid[row][j] = 1;
            }
        };

        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (vector<int>& v : guards) {
            int i = v[0];
            int j = v[1];
            grid[i][j] = 2;
        }

        for (vector<int>& v : walls) {
            int i = v[0];
            int j = v[1];
            grid[i][j] = 3;
        }

        for (vector<int>& g : guards) {
            int i = g[0];
            int j = g[1];
            marki(i, j, grid);
        }

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
};
