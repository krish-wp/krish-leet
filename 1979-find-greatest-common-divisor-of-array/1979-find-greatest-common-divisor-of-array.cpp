class Solution {
public:
    int gcd(int a , int b)
    {
        if(a > b) swap(a,b);
        if(a == 0) return b;
        return gcd(b%a , a);
    }


    int findGCD(vector<int>& nums) {
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin() , nums.end()); 

        return gcd(mini,maxi);
    }
};