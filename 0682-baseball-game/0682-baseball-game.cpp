class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        int ans = 0;
        for(auto ops : operations) {
            if(ops == "+") {
                int score1 = s.top();
                s.pop();
                int score2 = s.top();
                s.push(score1);
                ans += score1 + score2;
                s.push(score1 + score2);
            }
            else if(ops == "D") {
                int score = s.top();
                ans += 2 * score;
                s.push(2 * score);
            }
            else if(ops == "C") {
                int score = s.top();
                s.pop();
                ans -= score;
            }
            else {
                s.push(stoi(ops));
                ans += (stoi(ops));
            }
        }
        return ans;
    }
};