class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> temp =  score;
        sort(temp.begin(), temp.end(), greater<int>());
        unordered_map<int, int> m;
        for(int i=0; i<n; i++) m[temp[i]] = i;
        vector<string> ans(n);
        for(int i=0; i<n; i++) {
            if(m[score[i]] == 0) ans[i] = "Gold Medal";
            else if(m[score[i]] == 1) ans[i] = "Silver Medal";
            else if(m[score[i]] == 2) ans[i] = "Bronze Medal";
            else ans[i] = to_string(m[score[i]] + 1);
        }
        return ans;
    }
};