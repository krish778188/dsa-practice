class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int ans = 0;
        while(i < n) {
            int j = i;
            while(j < n && nums[j] == nums[i]) j++;
            int count = j-i;
            if(count >= 2) ans += 2;
            else ans++;

            if(count > 2) {
                int st = i+2;
                int k = j;
                while(k < n) {
                    nums[st] = nums[k];
                    st++; k++;
                }
                n -= count-2;
            }
            
            i += min(count, 2);
        }
        return ans;
    }
};