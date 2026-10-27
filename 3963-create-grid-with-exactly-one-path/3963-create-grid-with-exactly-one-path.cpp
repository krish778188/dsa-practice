class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        for(int i=0; i<m; i++) {
            string temp;
            if(i == 0) temp.assign(n, '.');
            else temp.assign(n, '#');
            temp[n-1] = '.';
            ans.push_back(temp);
        }
        return ans;
    }
};