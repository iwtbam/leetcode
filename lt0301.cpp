#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res = {};
        remove(move(s), {'(', ')'}, 0, 0, res);
        return res;        
    }

    void remove(std::string s, const vector<char>& par, int m, int n, vector<string>& res){
        int stack = 0;
        int size = s.size();
        for(int i = m; i < size; i++){
            if(s[i] == par[0])
                stack++;
            if(s[i] == par[1])
                stack--;
            if(stack >= 0)
                continue;

            for(int j = n; j <= i; j++){
                if(s[j] == par[1] && (j == n || s[j - 1]!=par[1])){
                    auto ss = s.substr(0, j) + s.substr(j + 1);
                    remove(move(ss), par, i, j, res);
                }
            }
            
            return;
        }

        reverse(s.begin(), s.end());
        if(par[0]=='('){
            remove(move(s), {par[1], par[0]}, 0, 0, res);
        }else{
            res.push_back(move(s));
        }
    }
};