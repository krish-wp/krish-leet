class Solution {
public:
vector<vector<int>> dp;
    int solve(vector<int>& coins, int i , int left)
    {
        int n = coins.size();
        if(left==0) return 1;
        if(i >= n) return 0;

        if(dp[i][left] != -1) return dp[i][left];

        int skip = solve(coins , i+1,left);
        int take = 0;
        if(left >= coins[i])
        {
            take = solve(coins , i , left - coins[i]);
        }

        return dp[i][left] = skip + take;
    }

    int change(int amount, vector<int>& coins) {
        int n  = coins.size();
        dp.resize(n,vector<int> (amount+1,-1));
        return solve(coins, 0 , amount);
    }
};