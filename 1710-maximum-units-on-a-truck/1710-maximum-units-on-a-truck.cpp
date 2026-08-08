class Solution {
    static bool compare(vector<int> &a, vector<int> &b) {
        double a1 = a[1];
        double b1 = b[1];
        return a1 > b1;
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int ans = 0;
        for(int i=0; i<n; i++) {
            int wt = boxTypes[i][0];
            int val = boxTypes[i][1]*boxTypes[i][0];
            if(wt <= truckSize) {
                ans += val;
                truckSize -= wt;
            } else {
                ans += boxTypes[i][1] * truckSize;break;
            }
        }
        return ans;
    }
};