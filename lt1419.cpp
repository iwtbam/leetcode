#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char, int> record = {
            {'c', 0},
            {'r', 1},
            {'o', 2},
            {'a', 3},
            {'k', 4}
        };
        
        
        vector<int> nums = {0, 0, 0, 0, 0};
        
        size_t n = croakOfFrogs.size();
        
        for(int i = 0; i < n; i++){
            int c =record[croakOfFrogs[i]];
            if(c == 0){
                if(nums[4] != 0){
                    nums[4] -= 1;
                }
                nums[0] += 1;
            }else{
                if(nums[c - 1] == 0){
                    return -1;    
                }
                nums[c - 1] -= 1;
                nums[c] += 1;
            }
        }
        
        for(int i = 0; i < 4; i++){
            if(nums[i] != 0)
                return -1;
        }
        
        return nums[4];
        
    }
};