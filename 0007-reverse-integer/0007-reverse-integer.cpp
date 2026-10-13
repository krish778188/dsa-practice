class Solution {
public:
    int reverse(int x) {
        long long num = x, rev = 0;
        if(num < 0) num = -num;
        string newNum = "";
        while(num > 0) {
            newNum += to_string(num%10);
            num /= 10;
        }
        for(char c : newNum) {
            rev = rev*10 + (c-'0');
        }
        if(x < 0) rev = -rev;
        if(rev > INT_MAX || rev < INT_MIN) return 0;
        return (int)rev;
    }
};