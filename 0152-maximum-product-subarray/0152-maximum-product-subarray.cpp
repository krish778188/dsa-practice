class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dpMax(n);
        vector<int> dpMin(n);
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];
        int maxP = nums[0];
        for(int i=1; i<n; i++) {
            dpMax[i] = max({dpMin[i-1]*nums[i], dpMax[i-1]*nums[i], nums[i]});
            dpMin[i] = min({dpMin[i-1]*nums[i], dpMax[i-1]*nums[i], nums[i]});;
            maxP = max(maxP, dpMax[i]);
        }
        return maxP;
    }
};