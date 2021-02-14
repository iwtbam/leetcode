#include <vector>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res = {};
        int size = asteroids.size();
        if(size == 0)
            return res;

        res.push_back(asteroids[0]);
        for(int i = 1; i < size; i++){
            bool is_push = true;
            
            while(is_push && res.size() && res.back() > 0 && asteroids[i] < 0)
            {
                if(abs(asteroids[i]) > abs(res.back()))
                    res.pop_back();
                else if(abs(asteroids[i]) < abs(res.back()))
                    is_push = false;
                else{
                    res.pop_back();
                    is_push = false;
                }
                
                   
            }
            
            if(is_push)
                res.push_back(asteroids[i]);
        }
       
        return res;
    }
};