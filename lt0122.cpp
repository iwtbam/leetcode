#include <vector>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices){
        int sum = 0;
        int size = prices.size();
        for(int i = 0; i < size - 1; i++)
        {
            if(prices[i] < prices[i+1])
                sum +=  prices[i+1] - prices[i];
        }

        return sum;
    }
};