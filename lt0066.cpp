#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int bit = 1;
        int size = digits.size();
        deque<int> res = {};
        vector<int>::reverse_iterator iter = digits.rbegin();
        for(; iter != digits.rend(); iter++)
        {
            if(!bit)
                break;
            int r = *iter + 1;            
            bit = r/10;
            r = r % 10;
            res.push_front(r);
        }
        
        
        
        for(;iter!=digits.rend();iter++)
            res.push_front(*iter);
        
        if(bit == 1)
            res.push_front(bit);
        
        return {res.begin(), res.end()};
    }
};