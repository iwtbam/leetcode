#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        char temp[10];
        vector<string> res = {};
        for(int i = 0; i < 12; i++)
        {
            for(int j = 0; j < 60; j++)
            {
                if((count_one_bit(i, 4) + count_one_bit(j, 6))==num)
                {
                    sprintf(temp, "%d:%02d", i, j);
                    res.push_back({temp});
                }
            }
        }
        return res;
    }

    int count_one_bit(int num, int offset){
        int count = 0;
        for(int i = 0; i < offset; i++)
        {
            int bit = 1 <<  i;
            if(bit & num)
                count++;
        }
        return count;
    }
};