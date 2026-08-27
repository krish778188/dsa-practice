class Solution {
public:
    int dpM(vector<int>& nums, int tar, int n, vector<vector<int>> &dp, int offset) {
        if(n == 0) return tar == 0;

        int index = tar + offset;
        if(index < 0 || index >= dp[0].size()) return 0;

        if(dp[n][index] != -1) return dp[n][index];
        int add = dpM(nums, tar - nums[n-1], n-1, dp, offset);
        int sub = dpM(nums, tar + nums[n-1], n-1, dp, offset);
        return dp[n][index] = add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int numsSum = 0;
        for(int i=0; i<n; i++) numsSum += nums[i];
        vector<vector<int>> dp(n+1, vector<int>(2*numsSum + 1, -1));
        if(target > numsSum || target < -numsSum) return 0;
        return dpM(nums, target, n, dp, numsSum);
    }
};