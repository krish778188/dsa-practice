class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool> vis(n+1, false);
        queue<int> q;
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        q.push(1);
        vis[1] = true;
        int ans = INT_MAX;
        while(q.size() > 0) {
            int curr = q.front();
            q.pop();
            for(auto neigh : adj[curr]) {
                int next_node = neigh.first;
                int dist = neigh.second;
                ans = min(ans, dist);
                if(!vis[next_node]) {
                    q.push(next_node);
                    vis[next_node] = true;
                }
            }
        }
        return ans;
    }
};