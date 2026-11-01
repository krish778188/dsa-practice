class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_elem = nums[0], sum_elem = 0;
        for(int num : nums) {
            min_elem = min(min_elem, num);
            sum_elem += num;
        }
        return sum_elem - (nums.size() * min_elem);
    }
};