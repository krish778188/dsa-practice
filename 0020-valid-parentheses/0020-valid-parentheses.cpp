class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 1) return false;
        stack<char> br;
        for(int i=0; i<s.size(); i++) {
            if((s[i] == '(') || (s[i] == '{') || (s[i] == '[')) br.push(s[i]);
            else if(br.empty() || (s[i] == ')' && br.top() != '(') || (s[i] == '}' && br.top() != '{') || (s[i] == ']' && br.top() != '[')) return false;
            else br.pop();
        }
        if(br.empty()) return true;
        else return false;
    }
};