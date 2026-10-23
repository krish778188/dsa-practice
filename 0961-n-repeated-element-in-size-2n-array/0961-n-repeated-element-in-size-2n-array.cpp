class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size()/2;
        unordered_map<int, int> m;
        for(int num : nums) {
            m[num]++;
            if(m[num] == n) return num;
        }
        return -1;
    }
};