#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:

    Solution(){
        memo = vector<int>(kDays, -1);
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->costs = costs;
        for(auto day:days)
            dayset.insert(day);
        return dp(1);
    }

    int dp(int i){
        if(i > 365)
            return 0;
        if(memo[i]!=-1)
            return memo[i];
        
        int ans;
        if(dayset.find(i)!=dayset.end())
            ans = min(dp(i+1) + costs[0], min(dp(i+7) + costs[1], dp(i+30) + costs[2]));
        else
            ans = dp(i+1);
        
        memo[i] = ans;
        return ans;
    }

private:
    vector<int> memo;
    vector<int> costs;
    set<int> dayset;
    static const int kDays = 366;
};