class Solution {
public:
    int robbi(vector<int>& nums, int i, int j) {
        if (i > j)
            return 0;
        if (i == j)
            return nums[i];

        int n = nums.size();
        vector<int> ans(n, 0);

        ans[i] = nums[i];
        ans[i + 1] = max(nums[i], nums[i + 1]);

        for (int k = i + 2; k <= j; k++) {
            ans[k] = max(ans[k - 1], ans[k - 2] + nums[k]);
        }

        return ans[j];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        return max(robbi(nums, 0, n - 2), robbi(nums, 1, n - 1));
    }
};