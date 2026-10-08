class Solution {
    void backtracking(string &s, int i, vector<string> &ans) {
        if(i == s.length()) {
            ans.push_back(s);
            return;
        }
        if(isdigit(s[i])) backtracking(s, i+1, ans);
        else {
            s[i] = toupper(s[i]);
            backtracking(s, i+1, ans);
            s[i] = tolower(s[i]);
            backtracking(s, i+1, ans);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        backtracking(s, 0, ans);
        return ans;
    }
};