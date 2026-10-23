class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        if(is_sorted(nums.begin(), nums.end())) return 0;
        int ans = -1;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] != i) ans &= nums[i];
        }
        return ans;
    }
};