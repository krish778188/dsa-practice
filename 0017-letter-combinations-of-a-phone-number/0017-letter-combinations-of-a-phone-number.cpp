class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, vector<char>> m;
        queue<char> q;
        for (char c = 'a'; c <= 'z'; c++) {
            q.push(c);
        }
        for(int i=2; i<=9; i++) {
            m[i].push_back(q.front());
            q.pop();
            m[i].push_back(q.front());
            q.pop();
            m[i].push_back(q.front());
            q.pop();
            if(i == 7 || i == 9) {
                m[i].push_back(q.front());
                q.pop();
            }
        }
        int size = 1;
        for(int i=0; i<digits.length(); i++) {
            size *= m[digits[i] - '0'].size();
        }
        vector<string> ans;
        for(int i=0; i<size; i++) {
            string temp = "";
            int x = i;
            for(int j=digits.length()-1; j>=0; j--) {
                int digit = digits[j] - '0';
                int index = x % m[digit].size();
                temp = m[digit][index] + temp;
                x /= m[digit].size();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};