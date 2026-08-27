class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int curr_max = prices[n-1];
        int ans = 0;
        for(int i=n-2; i>=0; i--) {
            if(prices[i] <= curr_max) ans = max(ans, curr_max - prices[i]);
            curr_max = max(curr_max, prices[i]);
        }
        return ans;
    }
};