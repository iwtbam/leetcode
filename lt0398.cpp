#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0;i < size; i++){
            int num = nums[i];
            look_table[num].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int>& eles = look_table[target];
        return eles[rand() % eles.size()];
    }

    unordered_map<int, vector<int>> look_table;
};
