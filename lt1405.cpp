// https://leetcode-cn.com/problems/longest-happy-string/
// longest happy string
class Solution {
public:

    string longestDiverseString(int a, int b, int c) {
        vector<vector<int>> words = {{a, 0}, {b, 1}, {c, 2}};
        string res = {};
        while(res.size() < a + b + c){
            sort(words.begin(), words.end(), greater<vector<int>>());
            if(res.size() > 0 && res.back() == words[0][1] + 'a'){
                if(words[1][0]-- > 0) 
                    res.push_back(words[1][1] + 'a');
                else
                    return res;
            }else{
                if(words[0][0]-- > 0)
                    res.push_back(words[0][1] + 'a');
                if(words[0][0]-- > 0)
                    res.push_back(words[0][1] + 'a');
            }
        }
        return res;
    }
};