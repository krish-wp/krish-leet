class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;

        for (char c : text) {
            if (c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n')
                mp[c]++;
        }

        int m1 = 0, c1 = 0, m2 = 0, c2 = 0, c3 = 0;
        for (auto x : mp) {
            if (x.first == 'b')
                c1 += x.second;
            else if (x.first == 'a')
                c2 += x.second;
            else if (x.first == 'n')
                c3 += x.second;
        }
        m1 = min(c1, min(c2, c3));

        c1 = 0, c2 = 0;
        for (auto x : mp) {
            if (x.first == 'l')
                c1 += x.second;
            else if (x.first == 'o')
                c2 += x.second;
        }
        m2 = min(c1, c2);

        m2 /= 2;

        cout << m1 << " " << m2;

        return min(m1, m2);
    }
};