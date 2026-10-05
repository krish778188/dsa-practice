class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        stack<int> scores;
        int score = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                scores.push(score);
                st.push(i);
                score = 0;
            }
            else {
                int open = st.top();
                st.pop();
                int prev = scores.top();
                scores.pop();
                if(open == i-1) score = prev + 1;
                else score = prev + 2*score;
            }
        }
        return score;
    }
};