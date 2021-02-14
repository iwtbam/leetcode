// https://leetcode-cn.com/problems/reduce-array-size-to-the-half/
// reduce array size to the half
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> count = {};
        size_t size = arr.size();
        for(int i = 0; i < size; i++){
            count[arr[i]]++;
        }
        
        vector<pair<int, int>> count_arr = {count.begin(), count.end()};
        
        sort(count_arr.begin(), count_arr.end(), [](const pair<int, int>& p1, const pair<int, int>& p2){
            return p2.second < p1.second;
        });
        
        
        size_t half = (size + 1) / 2;
        size_t num  = 0;
        int res = 0;
        for(auto [key, value] : count_arr){
            num += value;
            res += 1;
            if(num >= half)
                return res;
        }
        return res;
    }
};