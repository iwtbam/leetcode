// https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters/
// find words that can be formed by characters
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int record[26] = {0};
        int temp[26] = {0};
        int res = 0;
        for(int i = 0; i < chars.size(); i++){
            record[chars[i]-'a']++;
        }

        for(string& word : words) {
            for(int i = 0; i < 26; i++){
                temp[i] = 0;
            }

            for(int j = 0; j < word.size(); j++){
                temp[word[j] - 'a']++;
            }

            bool flag = false;
            for(int i = 0; i < 26; i++){
                if(record[i] < temp[i]){
                    flag = true;
                    break;
                }
            }

            if(!flag) {
                res += word.size();
            }
        }

        return res;
    }
};