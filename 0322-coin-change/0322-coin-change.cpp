class Solution {
public:
vector<vector<int>> dp;
    int solve(vector<int>& coins, int i, int left) {

        if (left == 0)
            return 0;
        int n = coins.size();
        if (i == n)
            return INT_MAX;

            if(dp[i][left] != -1) return dp[i][left];

        int nottake = solve(coins, i + 1, left);
        int take = INT_MAX;
        if (coins[i] <= left) {
            take = solve(coins, i, left - coins[i]);
            if (take != INT_MAX) {
                take++;
            }
        }

        return dp[i][left]=min(nottake, take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n,vector<int> (amount+1,-1));
        int ans = solve(coins, 0, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};