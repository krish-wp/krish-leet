class Solution {
public:
    int gcd(int a, int b) {
        if (a > b)
            swap(a, b);
        if (a == 0)
            return b;

        return gcd(b % a, a);
    }
    int gcdOfOddEvenSums(int n) {
        int odd = n * n;
        int even = odd + n;
        return gcd(odd, even);
    }
};