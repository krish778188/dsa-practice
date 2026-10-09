class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long long first = LONG_MIN, sec = LONG_MIN, third = LONG_MIN;
        for(int i=0; i<n; i++) {
            if(nums[i] == first || nums[i] == sec || nums[i] == third) continue;
            if(nums[i] > first) {
                third = sec;
                sec = first;
                first = nums[i];
            }
            else if(nums[i] > sec) {
                third = sec;
                sec = nums[i];
            }
            else if(nums[i] > third) third = nums[i];
        }
        if(third == LONG_MIN) return first;
        return third;
    }
};