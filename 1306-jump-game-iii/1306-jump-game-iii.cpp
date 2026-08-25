class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<bool> vis(n);
        q.push(start);
        vis[start] = true;
        while(q.size() > 0) {
            int curr = q.front();
            if(arr[curr] == 0) return true;
            q.pop();
            if(curr - arr[curr] >= 0 && !vis[curr - arr[curr]]) {
                q.push(curr - arr[curr]);
                vis[curr - arr[curr]] = true;
            }
            if(curr + arr[curr] < n && !vis[curr + arr[curr]]) {
                q.push(curr + arr[curr]);
                vis[curr + arr[curr]] = true;
            }
        }
        return false;
    }
};