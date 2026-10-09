class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int curr = 0, maxLen = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                maxLen = max(maxLen, curr);
                curr = 0;
            }
            else curr++;
        }
        maxLen = max(maxLen, curr);
        return maxLen;
    }
};