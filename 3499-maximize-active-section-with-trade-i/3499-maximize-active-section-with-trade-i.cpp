class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();

        s = '1' + s + '1';

        cout << s << endl;

        vector<int> cn;
        int c1 = 0;

        for (int i = 1; i <= n; i++) {
            if (s[i] == '1') {
                c1++;
            }
        }

        int i = 0;
        while (i <= n + 1) {
            int count = 0;
            while (s[i] == '1') {
                count++;
                i++;
            }
            cn.push_back(count);
            count = 0;
            while (s[i] == '0') {
                count++;
                i++;
            }
            cn.push_back(count);
        }
        cn.pop_back();

        int maxi = 0;

        for (int i = 1; i < cn.size() - 1; i++) {
            if (i % 2 == 0) {
                maxi = max(maxi, cn[i - 1] + cn[i + 1]);
            }
        }

        return maxi + c1;
    }
};