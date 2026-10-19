class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> s;
        for(int i=0; i<num.length(); i++) {
            int n = (num[i] - '0');
            while(s.size() > 0 && s.top() > n && k > 0) {
                s.pop();
                k--;
            }
            s.push(n);
        }
        while(k > 0 && !s.empty()) {
            s.pop();
            k--;
        }
        string ans = "";
        while(!s.empty()) {
            ans += char(s.top() + '0');
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        int i = ans.find_first_not_of('0');
        if (i == string::npos) return "0";
        
        return ans.substr(i);
    }
};