class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1]; 
        });
        int curr_end = -1001, max_chain = 0;
        for(auto pair : pairs) {
            if(pair[0] > curr_end) {
                curr_end = pair[1];
                max_chain++;
            }
        }
        return max_chain;
    }
};