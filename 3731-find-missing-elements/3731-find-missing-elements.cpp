class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_set<int> s;
        for(int i=0; i<n; i++) s.insert(nums[i]);
        int st = nums[0], end = nums[n-1];
        vector<int> ans;
        for(int i=st+1; i<end; i++) {
            if(s.find(i) == s.end()) ans.push_back(i);
        }
        return ans;
    }
};