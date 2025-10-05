class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        queue<pair<int,int>> pq, aq;

        // Pacific borders (top row + left col)
        for (int j = 0; j < n; j++) {
            pacific[0][j] = true;
            pq.push({0, j});
        }
        for (int i = 0; i < m; i++) {
            pacific[i][0] = true;
            pq.push({i, 0});
        }

        // Atlantic borders (bottom row + right col)
        for (int j = 0; j < n; j++) {
            atlantic[m-1][j] = true;
            aq.push({m-1, j});
        }
        for (int i = 0; i < m; i++) {
            atlantic[i][n-1] = true;
            aq.push({i, n-1});
        }

        bfs(heights, pq, pacific);
        bfs(heights, aq, atlantic);

        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

private:
    void bfs(vector<vector<int>>& heights, queue<pair<int,int>>& q, vector<vector<bool>>& visited) {
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (auto& d : directions) {
                int x = i + d[0], y = j + d[1];
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                if (visited[x][y]) continue;
                if (heights[x][y] < heights[i][j]) continue;

                visited[x][y] = true;
                q.push({x, y});
            }
        }
    }
};
