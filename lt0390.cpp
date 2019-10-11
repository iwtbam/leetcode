#include <vector>
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        
        vector<int> record = {};
        int i = n;
        for(; i != 1; i /= 2)
            record.push_back(i);
        int num = 1;
        for(int i = record.size() - 1; i >=0 ; i--)
        {
            if((i+1) % 2)
                num = 2 * num;
            else
            {
                if(record[i] % 2)
                    num = 2 * num;
                else
                    num = 2 * num - 1;
            }            
        }
        return  num;
    }
};