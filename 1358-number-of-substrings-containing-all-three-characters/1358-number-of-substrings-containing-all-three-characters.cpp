class Solution {
public:
    int atMost0(string& s) {
        unordered_map<int, int> mp;
        int n = s.length();
        int j = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
            while (mp.size() >= 3) {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    mp.erase(s[j]);
                }
                j++;
            }
            ans += (i - j + 1);
        }
        return ans;
    }

    int numberOfSubstrings(string s) {
        long long n = s.length();
        long long total =  n* (n + 1) / 2;
        return (int)(total - (long long)atMost0(s));
    }
};