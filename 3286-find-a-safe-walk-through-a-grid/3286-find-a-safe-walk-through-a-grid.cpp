class Solution {
public:
    int to_reach(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));

        queue<pair<int, int>> pq;

        pq.push({0, 0});

        if (grid[0][0] == 1) {
            cost[0][0] = 1;
        } else {
            cost[0][0] = 0;
        }

        while (!pq.empty()) {
            auto [x, y] = pq.front();
            pq.pop();

            cout << x << " " << y << endl;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    cost[nx][ny] > cost[x][y] + grid[nx][ny]) {
                    cost[nx][ny] = cost[x][y] + grid[nx][ny];
                    pq.push({nx, ny});
                }
            }
        }

        return cost[n - 1][m - 1];
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int need = to_reach(grid);

        cout << need << endl;
        return health >= need + 1 ? true : false;
    }
};