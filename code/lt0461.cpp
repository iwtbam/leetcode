#include <vector>

using namespace std;

#if defined S1

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = x ^ y;
        int mask = 1;
        int num = 0;
        for(int i = 0; i < 32; i++)
            if(res & (mask << i))
                num++;
        return num;
    }
};

#else 

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = x ^ y;
        int mask = 1;
        int num = 0;
        while(res){
            num++;
            res = res & (res - 1);
        }
        return num;
    }
};

#endif