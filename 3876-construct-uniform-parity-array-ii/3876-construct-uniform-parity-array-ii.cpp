class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_val = nums1[0];
        for(int i=1; i<nums1.size(); i++) {
            min_val = min(min_val, nums1[i]);
        }
        if(min_val%2 != 0) return true;
        else {
            for(int x : nums1) {
                if(x%2 != 0) return false;
            }
        }
        return true;
    }
};