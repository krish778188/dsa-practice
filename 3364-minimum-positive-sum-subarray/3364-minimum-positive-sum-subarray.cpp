class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        long long minSum = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            long long sum = 0;
            for(int j=i; j<nums.size(); j++) {
                sum += nums[j];
                if(j-i+1 >= l && j-i+1 <= r && sum > 0) minSum = min(sum, minSum);

                if(j-i+1 >= r) break;
            }
        }
        return (minSum == INT_MAX)?-1 : (int)minSum;
    }
};