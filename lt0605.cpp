#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int size = flowerbed.size();
        int pos = -2;

        for(int i = 0; i < size;i++)
        {
            if(flowerbed[i]){
                count += (i - pos - 2) / 2;
                pos = i;
            }
        }
        
        count += (size - pos - 1) / 2;
        return count >= n;
    }
};