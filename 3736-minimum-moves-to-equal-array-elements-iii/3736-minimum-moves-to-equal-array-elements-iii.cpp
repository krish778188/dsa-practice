class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_elem = nums[0], ans = 0;
        for(int num : nums) max_elem = max(max_elem, num);
        for(int num : nums) ans += abs(num - max_elem);
        return ans;
    }
};