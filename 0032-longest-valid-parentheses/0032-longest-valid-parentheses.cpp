class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> stack_s;
        stack_s.push(-1);
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') stack_s.push(i);
            else {
                stack_s.pop();
                if(stack_s.size() == 0) stack_s.push(i);
                else ans = max(ans, i-stack_s.top());
            }
        }
        return ans;
    }
};