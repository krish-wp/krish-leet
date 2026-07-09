// tabulation solution

class Solution {
public:
    vector<vector<int>> dp;

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n + 1, vector<int>(amount + 1, -1));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int i = 1; i <= amount; i++)
            dp[n][i] = INT_MAX;

        for (int i = n - 1; i >= 0; i--) {
            for (int left = 0; left <= amount; left++) {
                int nottake = dp[i + 1][left];
                int take = INT_MAX;
                if (coins[i] <= left) {
                    take = dp[i][left - coins[i]];
                    if (take != INT_MAX) {
                        take++;
                    }
                }
                dp[i][left] = min(take, nottake);
            }
        }
        return dp[0][amount] == INT_MAX ? -1 : dp[0][amount];
    }
};