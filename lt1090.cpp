#include <vector>
#include <unordered_map>

using namespace std;

#if defined (S1)
//2019-06-17:11-36 回溯超时 但是思路没啥问题
//2019-09-18:10-14 回溯的是可以, 但是样例的数量可以到20000, 题目的感觉其实贪心就可以
class Solution {
public:
    
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        unordered_map<int, int> record;
        return helper(values, labels, record, num_wanted,0,  use_limit, 0);
    }

    int helper(vector<int>& values, vector<int>& labels, unordered_map<int, int>& record, int num_wanted, int sum, int use_limit, int step){
        
        if(num_wanted == 0)
            return sum;
        
        int res = sum;
      
        for(int i = step; i < values.size(); i++)
        {
            if(record[labels[i]] >= use_limit)
                continue;
            
            record[labels[i]]++;
            res = max(res, helper(values, labels, record, num_wanted - 1 , sum + values[i], use_limit, i+1));
            record[labels[i]]--;
        }
        
        return res;
    }
};
#else

#endif