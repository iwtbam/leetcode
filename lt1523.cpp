// https://leetcode-cn.com/problems/count-odd-numbers-in-an-interval-range/
// count odd numbers in an interval range
class Solution {
public:
    int countOdds(int low, int high) {
        
        int num = high - low + 1;
        if(low % 2 == 1  && high % 2 == 1)
            return num / 2 + 1;
        
        return num / 2;
        
    }
};