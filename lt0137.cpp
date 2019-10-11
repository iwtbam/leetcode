#include <set>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


#define S2

#if defined S1

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    
        set<long long> sn(nums.begin(), nums.end());
        long long s1 = sum(sn);
        long long s2 = sum(nums);
        return (s1 * 3 - s2) / 2;
    }
    
    template<typename SeqType>
    long long sum(SeqType seq){
        long long res = 0;
        for(auto iter = seq.begin(); iter!=seq.end();iter++)
            res += *iter;
        return res;
    }
};


#elif  defined S2

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int one{0}, two{0}, three{0};

        for(int i = 0; i < nums.size(); i++){
            two |= one & nums[i];
            one ^= nums[i];
            three = two & one;
            one &=~three;
            two &=~three;
        }
        return one;
    }
};


#endif
