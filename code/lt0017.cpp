#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        vector<string> res = {};
        helper(digits, 0, res, string());
        return res;
    }
    
    
    void helper(string& digits, int step, vector<string>& res, string s){
        int size = digits.size();

        string ds = infos[digits[step] - '0'];
        for(int j = 0; j < ds.size(); j++)
        {
            s.push_back(ds[j]);
            helper(digits, step + 1, res, s);
            s.pop_back();
        }

        
        if(s.size() == size)
            res.push_back(s);
    }
private:
    unordered_map<int, string> infos = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };
};