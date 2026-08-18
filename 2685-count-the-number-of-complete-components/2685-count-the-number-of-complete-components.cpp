class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n, false);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                int vertex = 0, edge = 0;
                queue<int> q;
                q.push(i);
                vis[i] = true;
                while(q.size() > 0) {
                    int curr = q.front();
                    q.pop();
                    vertex++; edge += adj[curr].size();
                    for(int neigh : adj[curr]) {
                        if(!vis[neigh]) {
                            vis[neigh] = true;
                            q.push(neigh);
                        }
                    }
                }
                if(edge == vertex*(vertex-1)) ans++;
            }
        }
        return ans;
    }
};