class Solution {
public:
    int minInsertions(string s) {
        stack<int> st;
        int n = s.length();
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '(') st.push(i);
            else {
                if(i+1 < n && s[i+1] == ')') {
                    if(st.empty()) ans++;
                    else st.pop();
                    i++;
                }
                else {
                    ans++;
                    if(st.empty()) ans++;
                    else st.pop();
                }
            }
        }
        return ans + 2*st.size();
    }
};