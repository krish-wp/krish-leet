class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto r : roads)
        {
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }

        vector<int> vis(n+1,0);
        vis[1]=1;
        queue<int> q;
        q.push(1);
        int mini = INT_MAX;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto [x,d] : adj[node])
            {
                mini = min(mini , d);
                if(!vis[x])
                {
                    vis[x]=1;
                    q.push(x);
                }
            }
        }
        return mini;
    }
};