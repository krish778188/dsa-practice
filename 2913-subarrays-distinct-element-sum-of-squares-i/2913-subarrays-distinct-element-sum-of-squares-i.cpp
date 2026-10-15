class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
           unordered_map<int, int> m;  
            for(int j=i; j<n; j++) {
                m[nums[j]]++;
                int distinct = m.size();
                ans += distinct*distinct;
            }
        }
        return ans;
    }
};