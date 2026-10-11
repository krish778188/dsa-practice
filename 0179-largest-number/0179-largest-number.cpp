class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            string strA = to_string(a);
            string strB = to_string(b);
            return strA + strB > strB + strA;
        });
        if(!nums.empty() && nums[0] == 0) return "0";
        string ans;
        for(int num : nums) {
            ans += to_string(num);
        }
        return ans;
    }
};