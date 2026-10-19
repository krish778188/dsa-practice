class Solution {
    string decode(string s, int& i) {
        string ans = "";
        while(i < s.length() && s[i] != ']') {
            if(isdigit(s[i])) {
                int k = 0;
                while(i < s.length() && isdigit(s[i])) {
                    k = k * 10 + (s[i] - '0');
                    i++;
                }
                i++;
                string temp = decode(s, i);
                i++;
                while(k--) {
                    ans += temp;
                }
            }
            else {
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
};