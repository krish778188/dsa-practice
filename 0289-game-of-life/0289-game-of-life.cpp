class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp = board;
        int n = board.size(), m = board[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int neigh = 0;
                if(i-1 >= 0) neigh += temp[i-1][j];
                if(j-1 >= 0) neigh += temp[i][j-1];
                if(i+1 < n) neigh += temp[i+1][j];
                if(j+1 < m) neigh += temp[i][j+1];

                if(i-1 >= 0 && j-1 >= 0) neigh += temp[i-1][j-1];
                if(i-1 >= 0 && j+1 < m) neigh += temp[i-1][j+1];
                if(i+1 < n && j-1 >= 0) neigh += temp[i+1][j-1];
                if(i+1 < n && j+1 < m) neigh += temp[i+1][j+1];


                if(temp[i][j] == 0 && neigh == 3) board[i][j] = 1;
                else if(temp[i][j] == 1 && (neigh < 2 || neigh > 3)) board[i][j] = 0;
            }
        }
    }
};