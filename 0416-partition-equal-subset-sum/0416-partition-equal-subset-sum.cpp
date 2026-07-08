class Solution {
private:
    // bool find(vector<int>& nums, int i, int sum) {
    //     if (sum == 0)
    //         return true;
    //     if (i < 0)
    //         return false;
    //     if (sum < 0)
    //         return false;

    //     return find(nums, i - 1, sum) || find(nums, i - 1, sum - nums[i]);
    // }

public:
    bool canPartition(vector<int>& nums) {
        int total = 0;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            total += nums[i];
        }

        if (total % 2 != 0)
            return false;

        vector<vector<int>> dp(n, vector<int>((total / 2) + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = 1;

        for (int i = 1; i < n; i++) {
            for (int sum = total / 2; sum > 0; sum--) {
                dp[i][sum] = dp[i - 1][sum];
                if (sum >= nums[i]) {
                    dp[i][sum] |= dp[i - 1][sum - nums[i]];
                }
            }
        }
        return dp[n - 1][total / 2];
        // return find(nums, n - 1, total / 2);
    }
};