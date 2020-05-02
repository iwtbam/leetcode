#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:

    void max_q_push(deque<int>& q, vector<int>& datas, int index, int k){
        if(q.size() > 0 && q.front() == index - k)
            q.pop_front();

        while(q.size() > 0 && datas[q.front()] < datas[index])
            q.pop_front();

        q.push_back(index); 
    }

    int max(deque<int>& q){
        if(q.size() == 0)
            return -1;
        return q.front();
    }

    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> dp = {nums.begin(), nums.end()};
        int res = dp[0];

        max_q_push(q, dp, 0, k);

        for(int i = 1; i < n; i++){
            int index = max(q);
            dp[i] = std::max(dp[i], dp[index] + nums[i]);
            max_q_push(q, dp, i, k);
            res = std::max(res, dp[i]);
        }

        return res;
    }

};