#include <vector>
#include <algorithm>

using namespace std;


//2019-07-28:10-58 不够优秀, 时间很长, 可以优化

class Solution {
public:

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto cmp = [](vector<int>& e1, vector<int>& e2)->bool{
            
            if(e1[0] == e2[0])
                return e1[1] < e2[1];
            
            return e1[0] > e2[0];
            
            
        };
        sort(people.begin(), people.end(), cmp);
        int size = people.size();
        vector<vector<int>> res = {};

        for(int i = 0; i < size; i++)
            res.insert(res.begin() + people[i][1], people[i]);

        return res;          
    }
};