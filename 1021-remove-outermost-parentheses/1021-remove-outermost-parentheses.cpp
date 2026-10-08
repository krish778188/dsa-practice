class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        string ans = "";
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                if(!st.empty()) ans.push_back('(');
                st.push(i);
            }
            else {
                st.pop();
                if(!st.empty()) ans.push_back(')');
            }
        }
        return ans;
    }
};