class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();
        vector<int> res(n1+n2);
        for(int i=n2-1; i>=0; i--) {
            for(int j=n1-1; j>=0; j--) {
                int mul = (num1[j] - '0') * (num2[i] - '0');
                int total = mul+res[i+j+1];
                res[i+j+1] = total%10; 
                res[i+j] += total/10;
            }
        }
        int i = 0;
        string ans = "";
        while(i < res.size() && res[i] == 0) i++;
        while(i < res.size()) {
            ans += to_string(res[i]);
            i++;
        }
        return ans.empty() ? "0" : ans;
    }
};