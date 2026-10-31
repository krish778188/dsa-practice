class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        int diag = m+n-1;
        for(int d = 0; d < diag; d++) {
            int row = (d < n) ? 0 : d - n + 1;
            int col = (d < n) ? d : n - 1;

            vector<int> temp;
            while(row < m && col >= 0) {
                temp.push_back(mat[row][col]);
                row++;
                col--;
            }
            if(d % 2 == 0) reverse(temp.begin(), temp.end());
            for(int x : temp) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};