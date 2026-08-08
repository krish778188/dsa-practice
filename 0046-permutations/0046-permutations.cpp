class Solution {
    unsigned long long factorial(int n) {
        if (n < 0) return 0;
        unsigned long long result = 1;
        for (int i = 1; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
public:
    vector<int> perm(vector<int>& nums) {
        bool has_next = std::next_permutation(nums.begin(), nums.end());
        if (has_next) return nums;
        return nums;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int itr = factorial(n);
        vector<vector<int>> ans;
        while(itr > 0) {
            ans.push_back(perm(nums));
            itr--;
        }
        return ans;
    }
};