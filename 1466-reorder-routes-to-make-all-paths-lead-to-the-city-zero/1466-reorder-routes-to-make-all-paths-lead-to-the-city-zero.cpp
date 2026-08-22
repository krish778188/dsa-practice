class Solution {
public:
    int ans  = 0;
    int dfs(int i, vector<vector<int>>& connections, vector<vector<int>> &adj, vector<bool> &vis) {
        vis[i] = true;
        for(auto edge_idx : adj[i]) {
            int u = connections[edge_idx][0];
            int v = connections[edge_idx][1];
            int neigh = (u == i)? v : u;

            if(!vis[neigh]) {
                if(u == i) ans++;
                dfs(neigh, connections, adj, vis);
            }
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        ans = 0;
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for(int i=0; i< connections.size(); i++) {
            adj[connections[i][0]].push_back(i);
            adj[connections[i][1]].push_back(i);
        }
        for(int i=0; i<n; i++) {
            if(!vis[i]) dfs(i, connections, adj, vis);
        }
        return ans;
    }
};