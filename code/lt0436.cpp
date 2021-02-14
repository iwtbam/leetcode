// https://leetcode-cn.com/problems/find-right-interval/
// find right interval
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> record = {};
        int size = intervals.size();
        for(int i = 0; i < size; i++){
            vector<int>& iv = intervals[i];
            if(record.count(iv[0]) == 0)
                record.insert({iv[0], i});
        }

        vector<int> res = {};

        for(int i = 0; i < size; i++){
            vector<int>& iv = intervals[i];
            auto iter = record.lower_bound(iv[1]);
            if(iter != record.end()){
                res.push_back(iter->second);
            }else{
                res.push_back(-1);
            }
        }
        return res;
    }
};