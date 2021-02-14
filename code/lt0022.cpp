#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution{
public:
    vector<string> generateParenthesis(int n){
        if(n==0)
            return {};
        vector<string> res = {};
        helper(res, {}, 0, 0, n);
        return res;
    }

    void  helper(vector<string>& res, string item, int left, int right, int n){
        if(item.size() == n * 2)
        {
            res.push_back(item);
            return;
        } 

        if(left < n)
            helper(res, item + '(', left + 1, right, n);
        
        if(left < right)
            helper(res, item + ')', left, right + 1, n);
        
    }
};