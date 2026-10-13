class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq(n);
        for(int i = 0; i < n; i++) {
            sq[i] = 1LL * nums[i] * nums[i];
        }
        sort(sq.begin(), sq.end());
        long long ans = 0;
        for(int i=0; i<n; i++) {
            if(i < (n + 1) / 2) ans += sq[n - 1 - i];
            else ans -= sq[n - 1 - i];
        }
        return ans;
    }
};