class Solution {
public:
// vector<vector<int>> dp;

    int solve(vector<int>& nums , int i , int sum, int& target)
    {
        int n = nums.size();
        if(i==n && sum == target) return 1;
        if(i==n ) return 0;

        // if(dp[i][sum] != -1) return dp[i][sum];

        int neg = solve(nums,i+1,sum-nums[i],target);
        int pos = solve(nums,i+1,sum+nums[i],target);

        return pos+neg;
    }



    int findTargetSumWays(vector<int>& nums, int target) {
        // int n = nums.size();
        // dp.resize(n , vector<int>(target+1,-1));
        return solve(nums , 0,0, target);
    }
};