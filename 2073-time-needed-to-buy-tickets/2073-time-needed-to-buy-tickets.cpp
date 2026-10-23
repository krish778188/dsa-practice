class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<pair<int, int>> q;
        int time = 0;
        for(int i=0; i<n; i++) q.push({tickets[i], i});
        while(true) {
            auto [ticket, i] = q.front();
            q.pop();
            ticket--;
            time++;
            if(i == k && ticket == 0) return time;
            if(ticket > 0) q.push({ticket, i});
        }
        return time;
    }
};