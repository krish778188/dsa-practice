class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(auto str : strs) {
            int val1 = count(str.begin(), str.end(), '1');
            int val0 = str.length() - val1;
            for(int i=m; i>=val0; i--) {
                for(int j=n; j>=val1; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - val0][j - val1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};