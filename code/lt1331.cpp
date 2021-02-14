// https://leetcode-cn.com/problems/rank-transform-of-an-array/
// rank transform of an array
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted_arr(arr.begin(), arr.end());
        sort(sorted_arr.begin(), sorted_arr.end());
        unordered_map<int, int> pos = {};
        size_t size = arr.size();
        int no = 1;
        for(int i = 0; i < size; i++){
            if(pos.count(sorted_arr[i]) == 0)
                pos[sorted_arr[i]] = no++;
        }
        
        vector<int> res = {};
        
        for(int i = 0; i < size; i++){
            res.push_back(pos[arr[i]]);
        }
        
        return res;
    }
};