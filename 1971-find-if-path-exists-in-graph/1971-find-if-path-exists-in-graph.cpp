class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(source);
        vis[source] = true;
        while(q.size() > 0) {
            int curr = q.front();
            if(curr == destination) return true;
            vis[curr] = true;
            q.pop();
            for(int neigh : adj[curr]) {
                if(!vis[neigh]) {
                    q.push(neigh);
                    vis[neigh] = true;
                }
            }
        }
        return false;
    }
};