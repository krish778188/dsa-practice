class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {
        q = {};
    }
    
    int ping(int t) {
        q.push(t);
        queue<int> temp = q;
        int req = 0;
        while(!temp.empty()) {
            if(temp.front() >= (t-3000) && temp.front() <= t) req++;
            temp.pop();
        }
        return req;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */