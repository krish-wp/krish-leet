class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        //for each subarray count target and check with subarray size to get the ans
        int n = nums.size();
        int ans=0;

        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=i;j<n;j++)
            {
                if(nums[j]==target) count++;
                if(count > (j-i+1)/2) ans++;
            }
        }
        return ans;
    }
};