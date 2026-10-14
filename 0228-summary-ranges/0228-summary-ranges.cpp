class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        if(n == 0) return ans;
        int st = nums[0], end;
        for(int i=1; i<n; i++) {
            if((nums[i] != (nums[i-1]+1))) {
                end = nums[i-1];
                if(st == end) {
                    ans.push_back(to_string(st));
                    st = nums[i];
                }
                else {
                    string temp = format("{}->{}", st, end);
                    ans.push_back(temp);
                    st = nums[i];
                }
            }
        }
        end = nums[n-1];
        if(st == end) {
            ans.push_back(to_string(st));
        }
        else {
            string temp = format("{}->{}", st, end);
            ans.push_back(temp);
        }
        return ans;
    }
};