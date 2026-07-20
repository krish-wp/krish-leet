class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> help = grid;

        for (int p = 0; p < k; p++) {
            help = grid;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m - 1; j++) {
                    help[i][j + 1] = grid[i][j];
                }

                if (i < n - 1)
                    help[i + 1][0] = grid[i][m - 1];
            }

            help[0][0] = grid[n - 1][m - 1];
            grid = help;
        }
        return help;
    }
};