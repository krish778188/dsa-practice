class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int, unordered_set<char>> m;
        for(int i=0; i<words.size(); i++) {
            for(char c : words[i]) m[i].insert(c);
        }  
        int ans = 0;
        for(int i=0; i<words.size(); i++) {
            for(int j=i+1; j<words.size(); j++) {
                bool similar = true;
                if(m[i].size() == m[j].size()) {
                    for(char c : m[j]) {
                        if(m[i].find(c) == m[i].end()) {
                            similar = false;break;
                        }
                    }
                }
                else similar = false;

                if(similar) ans++;
            }
        }
        return ans;
    }
};