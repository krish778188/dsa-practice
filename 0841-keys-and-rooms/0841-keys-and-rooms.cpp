class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        vector<bool> vis(rooms.size(), false);
        for(int i=0; i<rooms[0].size(); i++) q.push(rooms[0][i]);
        vis[0] = true;
        while(q.size() > 0) {
            int curr = q.front();
            vis[curr] = true;
            q.pop();
            for(int neigh : rooms[curr]) {
                if(!vis[neigh]) {
                    q.push(neigh);
                }
            }
        }
        for(int i=0; i<rooms.size(); i++) {
            if(!vis[i]) return false;
        }
        return true;
    }
};