class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return (k % 2 == 0) ? nums[0] : -1;
        if(k == 0) return nums[0];
        int maxi = -1;
        for(int i=0; i<min(k-1, n); i++) {
            maxi = max(maxi, nums[i]);
        }
        if(k < n) maxi = max(maxi, nums[k]);
        return maxi;
    }
};