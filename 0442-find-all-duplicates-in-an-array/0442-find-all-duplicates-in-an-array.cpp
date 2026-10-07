class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for(int i=0; i<n; i++) {
            if(ans[nums[i]-1] != -1) ans.push_back(nums[i]);
            else ans[nums[i]-1] = nums[i];
        }
        ans.erase(ans.begin(), ans.begin()+n);
        return ans;
    }
};