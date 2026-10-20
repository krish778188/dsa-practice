class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j = 0;
        for(int num : pushed) {
            s.push(num);
            while(!s.empty() && s.top() == popped[j]) {
                s.pop();j++;
            }
        }
        return s.empty();
    }
};