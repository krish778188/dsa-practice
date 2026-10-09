class Solution {
    int minJump(vector<int>& nums, vector<int> &dp, int i){
        int n = nums.size();
        if(i >= n-1) return 0;
        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;
        for(int j=1; j<=nums[i]; j++) {
            if(i+j < n) {
                int jump = minJump(nums, dp, i+j);
                if(jump != INT_MAX) {
                    ans = min(ans, jump+1);
                }
            }
        }
        return dp[i] = ans;
    }
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int ans = 0;
        return minJump(nums, dp, 0);
    }
};