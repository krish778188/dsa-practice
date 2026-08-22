class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        if(q.size() == 0 || q.size() == grid.size()*grid.size()) return -1;
        int dist = -1;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(q.size() > 0) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                auto [r, c] = q.front();
                q.pop();
                for(auto dir : dirs) {
                    int ro = r + dir.first;
                    int co = c + dir.second;
                    if(ro >= 0 && co >= 0 && ro < grid.size() && co < grid.size() && grid[ro][co] == 0) {
                        grid[ro][co] = 1;
                        q.push({ro, co});
                    }
                }
            }
            dist++;
        }
        return dist;
    }
};