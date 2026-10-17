class Solution {
    int getDigitSum(int num) {
    int sum = 0;
    num = abs(num);    
    while (num > 0) {
        sum += num % 10;  
        num /= 10;        
    }
    return sum;
}
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int, int>, int>> arr(n);
        for(int i = 0; i < n; i++) {
            arr[i] = {{getDigitSum(nums[i]), nums[i]}, i};
        }
        sort(arr.begin(), arr.end());
        vector<int> temp(n);
        vector<int> pos(n);
        for(int i=0; i<n; i++) {
            pos[i] = i;
            temp[i] = i;
        }
        int swapping = 0;
        for(int i=0; i<n; i++) {
            int idx = arr[i].second;
            if(temp[i] != idx) {
                swapping++;
                int j = pos[idx];
                swap(temp[i], temp[j]);
                pos[temp[i]] = i;
                pos[temp[j]] = j;
            }
        }
        return swapping;
    }
};