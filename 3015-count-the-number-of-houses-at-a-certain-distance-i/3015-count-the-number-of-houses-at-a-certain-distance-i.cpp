class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> adj(n+1);
        adj[x].push_back(y);
        adj[y].push_back(x);
        for(int i=1; i<n; i++) {
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }
        vector<int> ans(n, 0);
        for(int i=1; i<=n; i++) {
            vector<int> dist(n+1, -1);
            queue<int> q;

            q.push(i);
            dist[i] = 0;

            while(q.size() > 0) {
                int curr = q.front();
                q.pop();
                for(int neigh : adj[curr]) {
                    if(dist[neigh] == -1) {
                        q.push(neigh);
                        dist[neigh] = dist[curr] + 1;
                        ans[dist[neigh]-1]++;
                    }
                }
            }
        }
        return ans;
    }
};