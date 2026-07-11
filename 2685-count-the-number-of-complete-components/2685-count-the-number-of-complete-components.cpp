class Solution {
public:

    void dfs(vector<vector<int>>& adj, int node,
             vector<int>& vis, vector<int>& comp) {
        vis[node] = 1;
        comp.push_back(node);

        for (int next : adj[node]) {
            if (!vis[next]) {
                dfs(adj, next, vis, comp);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> comp;
                dfs(adj, i, vis, comp);

                int sz = comp.size();
                bool complete = true;

                for (int node : comp) {
                    if (adj[node].size() != sz - 1) {
                        complete = false;
                        break;
                    }
                }

                if (complete)
                    ans++;
            }
        }

        return ans;
    }
};