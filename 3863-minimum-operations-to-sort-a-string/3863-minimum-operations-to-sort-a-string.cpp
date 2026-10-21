class Solution {
public:
    int minOperations(string s) {
        if(is_sorted(s.begin(), s.end())) return 0;
        if(s.length() == 2) return -1;
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());
        if (s.front() == mn || s.back() == mx) return 1;
        if (s.front() == mx && s.back() == mn) {
            int count_mn = count(s.begin(), s.end(), mn);
            int count_mx = count(s.begin(), s.end(), mx);
            if (count_mn == 1 && count_mx == 1) return 3;
        }
        return 2;
    }
};