#include <vector>

using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        
        if(n < 2)
            return 0;
        
        vector<int> record(n, 0);
        record[0] = 1;
        record[1] = 1;
        int count = 0;
        for(int i = 2; i < n; i++)
        {
            if(record[i] == 0)
                count++;
            for(int j = i; j < n; j+= i)
                record[j] = 1;
        }
        
        return count;   
    }
};