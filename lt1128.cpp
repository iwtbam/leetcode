// https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs/
// number of equivalent domino pairs
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> record = {};
        int count = 0;
        for(const vector<int>& dominoe :  dominoes){
            int size = dominoe.size();
            int angle_0 = 0, angle_180 = 0;
            for(int i = 0; i < size; i++){
                angle_0 = angle_0 * 10 + dominoe[i];
                angle_180 = angle_180 * 10 + dominoe[size - i - 1];
            }

            if(record.count(angle_0))
                record[angle_0]++;
            else if(record.count(angle_180))
                record[angle_180]++;
            else
                record[angle_180] = 1;
        }

        for(const auto [key, val] : record){
            count += (val * (val - 1)) / 2;
        }

        return  count;
    }
};