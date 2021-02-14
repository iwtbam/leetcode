// https://leetcode-cn.com/problems/shortest-completing-word/
// shortest completing word
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int lp[26] = {0};

        int lPSize = licensePlate.size();
        for(int i = 0; i < lPSize; i++){
            char c = licensePlate[i];
            if('a' <= c && c <= 'z')
                lp[c - 'a']++;

            if('A' <= c && c <= 'Z')
                lp[c - 'A']++;
        }

        int wSize = words.size();
        string res = {};
        for(int i = 0; i < wSize; i++){
            int item[26] = {0};
            int itemSize = words[i].size();
            for(int j = 0; j < itemSize; j++){
                char c = words[i][j];
                if('a' <= c && c <='z')
                    item[c - 'a']++;
                if('A' <= c && c < 'Z')
                    item[c - 'A']++;
            }

            bool flag = true;
            for(int i = 0; i < 26; i++){
                if(lp[i] > 0 && item[i] < lp[i]){
                    flag = false;
                    break;
                }
            }

            if(flag &&(res.empty() || itemSize < res.size()))
                res = words[i];
        }

        return res;
    }
};