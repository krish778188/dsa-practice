class Solution {
public:
    bool dp(int part1, int part2, vector<int>& nums, int i, vector<vector<int>>  &memo, int target) {
        if(part1 == part2) return true;
        if(i == nums.size() || part1 > target) return false;

        if(memo[i][part1] != -1) return memo[i][part1];

        return memo[i][part1] = dp(part1+nums[i], part2-nums[i], nums, i+1, memo, target) || dp(part1, part2, nums, i+1, memo, target);

    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i=0; i<n; i++) total += nums[i];
        if(total%2 != 0) return false;
        int target = total/2;
        vector<vector<int>> memo(n, vector<int>(target+1, -1));
        int part1 = 0, part2 = total, i = 0;
        return dp(part1, part2, nums, i, memo, target);
    }
};