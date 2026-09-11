class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> m(10, 0);
        for (int digit : digits)
            m[digit]++;
        int total = 0;
        for (int ones = 0; ones <= 8; ones += 2) {
            if (m[ones] > 0) {
                m[ones]--;
                for (int hundreds = 1; hundreds <= 9; hundreds++) {
                    if (m[hundreds] > 0) {
                        m[hundreds]--;
                        for (int tens = 0; tens <= 9; tens++) {
                            if (m[tens] > 0)
                                total++;
                        }
                        m[hundreds]++;
                    }
                }
                m[ones]++;
            }
        }
        return total;
    }
};