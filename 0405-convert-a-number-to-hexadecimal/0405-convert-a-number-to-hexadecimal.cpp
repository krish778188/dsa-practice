class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        string ans = "";
        string hex = "0123456789abcdef";
        unsigned int n = num;
        while(n > 0) {
            ans.insert(0, 1, hex[n%16]);
            n /= 16;
        }
        return ans;
    }
};