class Solution {
public:
    int gcd(int a , int b)
    {
        if(a > b) swap(a,b);
        if(a == 0 )return b;
        return gcd(b%a , a);
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n);
        int maxi = 0;

        for(int i=0;i<n;i++)
        {
            maxi = max(maxi, nums[i]);
            pre[i] = gcd(nums[i] , maxi);
        }

        sort(pre.begin(), pre.end());
        long long ans=0;

        for(int i=0;i<n/2;i++)
        {
            ans += (long long)gcd(pre[i] , pre[n-i-1]);
        }
        return ans;
    }
};