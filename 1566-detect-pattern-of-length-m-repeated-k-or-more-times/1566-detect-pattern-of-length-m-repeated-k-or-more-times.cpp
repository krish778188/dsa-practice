class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        for(int i=0; i<n; i++) {
            for(int j=i; j<=n; j++) {
                if(j-i+1 == m) {
                    int pattern = 0;
                    for(int l=i; l<n; l++) {
                        if(arr[l] == arr[i + (l-i)%m]) pattern++;
                        else break;
                    }
                    if(pattern >= m*k) return true;
                }
            }
        }
        return false;
    }
};