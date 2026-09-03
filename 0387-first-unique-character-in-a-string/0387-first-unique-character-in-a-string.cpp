class Solution {
public:
    int firstUniqChar(string s) {
        int idx= 0;
        unordered_map<char, int> m;
        for(auto ch : s) {
            m[ch]++;
        }
        for(int i=0; i<s.length(); i++) {
            if(m[s[i]] == 1) return i;
        }
        return -1;
    }
};