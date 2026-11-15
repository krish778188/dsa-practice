class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<long long> temp(arr.size());
        long long ans = 0;
        for(int i=0; i<arr.size(); i++) {
            if(i == 0) temp[i] = arr[i];
            else temp[i] = temp[i-1] + arr[i];
            if(temp[i] % 2 != 0) ans++;
        }
        long long currOdd = 0, currEven = 0;
        for(int i=0; i<arr.size(); i++) {
            if(temp[i] % 2 == 0) {
                currEven++;
                ans += currOdd;
            }
            else {
                currOdd++;
                ans += currEven;
            }
        }
        return ans%1000000007;
    }
};