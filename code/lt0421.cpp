#include <vector>
#include <string>
#include <unordered_set>
#include <cstdint>
#include <iostream>
using namespace std;


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        uint32_t mask = 0;
        for(int i = 31; i >= 0; i--){
            mask = mask | (1 << i);
            unordered_set<int> record;
            for(auto num: nums){
                record.insert(num & mask);
            }

            int temp = res | (1 << i);
            for(auto  prefix : record){
                if(record.find(prefix ^ temp) != record.end()){
                    res = temp;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> case2 = {14,15,9,3,2};

    vector<int> case1 = {3, 10, 5, 25, 2, 8};

    Solution s;

    int res = s.findMaximumXOR(case2);
    cout << res << endl;

    res = s.findMaximumXOR(case1);
    cout << res << endl;

    return 0;
}