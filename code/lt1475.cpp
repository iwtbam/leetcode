// https://leetcode-cn.com/problems/final-prices-with-a-special-discount-in-a-shop/
// final prices with a special discount in a shop
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res = {};
        size_t size = prices.size();
        for(int i = 0; i < size; i++){
            int cost = 0;
            for(int j = i + 1; j < size; j++){
                if(prices[j] <= prices[i]){
                    cost = prices[j];
                    break;
                }
            }
            res.push_back(prices[i] - cost);
        }
        
        return res;
    }
};