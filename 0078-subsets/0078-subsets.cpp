class Solution {
public:
    void powerSet(int i, vector<int>& nums, vector<int> &temp, set<vector<int>> &s) {
        if(i == nums.size()) {
            s.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        powerSet(i+1, nums, temp, s);
        temp.pop_back();
        powerSet(i+1, nums, temp, s);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        vector<vector<int>> ans;
        vector<int> temp;
        powerSet(0, nums, temp, s);
        for(auto val : s) {
            ans.push_back(val);
        }
        return ans;
    }
};