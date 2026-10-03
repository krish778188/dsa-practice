class Solution {
public:
    int sumOfDigits(int n) {
        int sum = 0;
        while(n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        long long sum = sumOfDigits(n);
        unordered_set<long long> vis;
        while(true) {
            if(sum == 1) return true;
            if(vis.find(sum) != vis.end()) break;
            vis.insert(sum);
            sum = sumOfDigits(sum);
        }
        return false;
    }
};