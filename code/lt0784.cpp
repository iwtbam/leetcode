#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int num = 0;
        int size = S.size();
        vector<int> pos = {};
        vector<string> res = {};
        
        for(int i = 0; i < size; i++)
        {
            if(!isdigit(S[i])){
                pos.push_back(i);
                num++;
            }
        }
        
        int total_num = (1 << num);
        
        for(int i = 0; i < total_num; i++){
            string temp = S;            
            for(int j = 0; j < num; j++)
            {
                if((1 << j) & i){
                    temp[pos[j]] ^= 32;
                }
            }
            
            res.push_back(temp);
        }
        
        return res;
        
    }
};