class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans;
        unordered_map<int, int> m(n1);
        for(int i=0; i<n1; i++) {
            if(m.find(nums1[i]) == m.end()) m[nums1[i]]++;
        }
        for(int i=0; i<n2; i++) {
            if(m.find(nums2[i]) != m.end() && m[nums2[i]] == 1) {
                ans.push_back(nums2[i]);
                m[nums2[i]]++;
            }
        }
        return ans;
    }
};