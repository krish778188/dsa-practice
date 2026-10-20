class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        int st = n, end = -1;
        for(int i=0; i<n; i++) {
            while(!s.empty() && nums[s.top()] > nums[i]) {
                st = min(st, s.top());
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1; i>=0; i--) {
            while(!s.empty() && nums[s.top()] < nums[i]) {
                end = max(end, s.top());
                s.pop();
            }
            s.push(i);
        }
        if(end == -1) return 0;
        return end - st + 1;
    }
};