#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int rows = nums.size();
        unordered_map<int, vector<int>> hash;
        
        for(int i = 0; i < rows; i++){
            int cols = nums[i].size();
            for(int j = 0; j < cols; j++){
                hash[i + j].push_back(nums[i][j]);
            }
        }

        vector<pair<int, vector<int>>> sorted = {hash.begin(), hash.end()};
        sort(sorted.begin(), sorted.end());

        vector<int> res = {};
        for(auto& [key, val] : sorted){
            res.insert(res.end(), val.rbegin(), val.rend());
        }

        return res;
        
    }
};