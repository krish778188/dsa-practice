class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int flower = 0;
        int size = flowerbed.size();
        for(int i = 0; i < size; i++) {
            if(flowerbed[i] == 0) {
                if((i == 0 || flowerbed[i-1] == 0) && (i == size-1 || flowerbed[i+1] == 0)) {
                    flower++;
                    flowerbed[i] = 1;
                }
            }
        }
        return flower >= n;
    }
};