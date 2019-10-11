#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res = {};
        for(int i = 0; i <= num; i++)
            res.push_back(helper(i));
        return res;
    }

    int helper(int i){
        int bits = 0;
        while(i)
        {
            if(i & 1)
                bits++;
            i = i >> 1;            
        }
        return bits;
    }
};