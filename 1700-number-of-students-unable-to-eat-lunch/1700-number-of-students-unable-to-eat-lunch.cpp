class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> s;
        queue<int> q;
        for(int i=sandwiches.size()-1; i>=0; i--) s.push(sandwiches[i]);
        for(int num : students) q.push(num);
        int rotation = 0;
        while(!s.empty() && !q.empty()) {
            if(s.top() == q.front()) {
                s.pop();
                q.pop();
                rotation = 0;
            }
            else {
                int temp = q.front();
                q.pop();
                q.push(temp);
                rotation++;
            }

            if(rotation == q.size()) break;
        }
        return q.size();
    }
};