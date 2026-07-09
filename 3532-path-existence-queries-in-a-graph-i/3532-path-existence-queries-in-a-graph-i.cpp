class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find_p(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find_p(parent[i]);
    }

    void unit(int i, int j) {
        int p_i = find_p(i);
        int p_j = find_p(j);
        if (p_i == p_j)
            return;

        if (rank[p_i] > rank[p_j]) {
            parent[p_j] = p_i;
        } else if (rank[p_j] > rank[p_i]) {
            parent[p_i] = p_j;
        } else {
            parent[p_i] = p_j;
            rank[p_j]++;
        }
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {

        vector<bool> ans;

        DSU dsu(n);
        for (int i = 1; i < n; i++) {
            if (abs(nums[i - 1] - nums[i]) <= maxDiff) {
                dsu.unit(i, i - 1);
            }
        }

        for (auto x : queries) {
            int u = x[0], v = x[1];
            if (dsu.find_p(u) == dsu.find_p(v)) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};