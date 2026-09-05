class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int min_idx = 0;
        vector<int> min_vec(n);
        int min_val = nums[n-1];
        min_vec[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--) {
            min_val = min(min_val, nums[i]);
            min_vec[i] = min_val;
        }
        int max_val = 0;
        for(int i=0; i<n; i++) {
            max_val = max(max_val, nums[i]);
            if(max_val - min_vec[i] <= k) return i;
        }
        return -1;
    }
};