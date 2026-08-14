class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxNum = 0;
        unordered_map<int, int> m;
        for(auto num : nums) {
            m[num]++;
            maxNum = max(maxNum, num);
        }
        vector<int> dp(maxNum+1, 0);
        dp[0] = 0;
        dp[1] = m[1];
        for(int i=2; i<=maxNum; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+(i*m[i]));
        }
        return dp[maxNum];
    }
};