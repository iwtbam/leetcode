// https://leetcode-cn.com/problems/string-matching-in-an-array/
// string matching in an array
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res = {};
        size_t size = words.size();
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(i == j)
                    continue;
                if(words[j].find(words[i]) != words[j].npos){
                    res.push_back(words[i]);
                    break;
                }
            }
        }

        return res;
    }
};