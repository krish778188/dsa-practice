class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m;
        for(int i=0; i<list1.size(); i++) m[list1[i]] = i;
        priority_queue<pair<int, string>, vector<pair<int, string>>,greater<pair<int, string>>> pq;
        vector<string> ans;
        for(int i=0; i<list2.size(); i++) {
            if(m.find(list2[i]) != m.end()) {
                pq.push({m[list2[i]] + i, list2[i]});
            }
        }
        if(pq.empty()) return ans;
        ans.push_back(pq.top().second);
        int minIdx = pq.top().first;
        pq.pop();
        while(!pq.empty() && pq.top().first == minIdx) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};