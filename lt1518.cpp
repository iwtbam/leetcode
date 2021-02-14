// https://leetcode-cn.com/problems/water-bottles/
// water bottles
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res  = numBottles;
        while(numBottles / numExchange){
            res += numBottles / numExchange;
            numBottles = numBottles % numExchange + numBottles / numExchange;
        }
        
        return res;
    }
};