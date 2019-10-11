#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        size_t size = primes.size();

        if(size == 0)
            return 0;

        vector<int> res = {1};
        vector<int> p(primes.size(), 0);
        int i = 1;
        while(i < n)
        {
            int temp = primes[0] * res[p[0]];
            
            for(int j = 1; j < size; j++)
                temp = min(primes[j] * res[p[j]], temp);

            for(int j = 0; j < size; j++)
            {
                if(temp == res[p[j]] * primes[j]){
                    p[j]++;
                    break;
                }
            }
            if(temp != res.back())
            {
                res.push_back(temp);
                i++;
            }
        }

        return res.back();
        
    }
};