#include <iostream>
#include <vector>

using namespace std;

//弱智题, 考虑下迭代器失效, 索引变化的情况就可以了

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        auto begin_iter = nums.begin();
        for(int i = size - 1; i >=0 ; i--)
            if(nums.at(i) == val)
                nums.erase(begin_iter + i);
        return nums.size();   
    }
};