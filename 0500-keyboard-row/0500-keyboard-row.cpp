class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> m;
        string r1 = "qwertyuiop", r2 = "asdfghjkl", r3 = "zxcvbnm";
        for(char c : r1) m[c] = 1;
        for(char c : r2) m[c] = 2;
        for(char c : r3) m[c] = 3;
        vector<string> ans;
        for(int i=0; i<words.size(); i++) {
            int row = -1;
            bool isPos = true;
            for(int j=0; j<words[i].size(); j++) {
                if(j == 0) row = m[tolower(words[i][0])];
                else {
                    if(m[tolower(words[i][j])] != row) {
                        isPos = false;
                        break;
                    }
                }
            }
            if(isPos) ans.push_back(words[i]);
        }
        return ans;
    }
};