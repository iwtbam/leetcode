#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int max_profit = 0;
        int profit = 0;
        for(int i = 0; i< size-1; i++){
           profit += (prices[i+1] - prices[i]);
           if(profit < 0)
               profit = 0;
            
           else 
           {
               if(max_profit < profit)
                   max_profit = profit;
           }
                
        }

        return max_profit;        
    }
};