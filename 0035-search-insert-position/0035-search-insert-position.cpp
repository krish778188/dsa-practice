class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, end = n-1;
        while(st < end) {
            int mid = st + (end-st)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) st = mid+1;
            else end = mid-1;
        }
        for(int i=0; i<n; i++) {
            if(nums[i] >= target) return i;
            else if(i == n-1) return i+1;
        }
        return -1;
    }
};