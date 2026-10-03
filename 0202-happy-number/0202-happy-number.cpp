constexpr std::array<int, 10000> generate_lookup_table() {
    std::array<int, 10000> table = {};
    for (int i = 0; i < 10000; ++i) {
        int sum = 0;
        int temp = i;
        while (temp > 0) {
            int digit = temp % 10;
            sum += digit * digit;
            temp /= 10;
        }
        table[i] = sum;
    }
    return table;
}

constexpr auto lookup_table = generate_lookup_table();

class Solution {
public:
    int getSumOfDigitsSquare(int n) {
        int chunk1 = n % 10000;
        int chunk2 = (n / 10000) % 10000;
        int chunk3 = n / 100000000;

        return lookup_table[chunk1] + lookup_table[chunk2] + lookup_table[chunk3];
    }
    bool isHappy(int n) {
        long long sum = getSumOfDigitsSquare(n);
        unordered_set<long long> vis;
        while(true) {
            if(vis.find(sum) != vis.end()) break;
            if(sum == 1) return true;
            vis.insert(sum);
            sum = getSumOfDigitsSquare(sum);
        }
        return false;
    }
};