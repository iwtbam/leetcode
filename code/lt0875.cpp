// https://leetcode-cn.com/problems/koko-eating-bananas/
// koko eating bananas
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        long long l = 1, r = accumulate(piles.begin(), piles.end(), 0LL);
        int n = piles.size();
        while(l < r){
            long long mid = (l + r) >> 1;
            long long time = 0;
            for(int i = 0; i < n; i++)
                time = time + piles[i] / mid + (piles[i] % mid ? 1 : 0);
            if(time <= H){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};