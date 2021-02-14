// https://leetcode-cn.com/problems/count-the-number-of-consistent-strings/
// count the number of consistent strings
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int record[26] = {0};
        size_t allow_size = allowed.size();
        for(int i = 0; i < allow_size; i++)
            record[allowed[i] - 'a'] = 1;
        
        int num = 0;
        size_t word_num = words.size();
        for(int i = 0; i < word_num; i++)
        {
            size_t word_size = words[i].size();
            int flag = 1;
            for(int j = 0; j < word_size; j++){
                if(record[words[i][j] - 'a'] == 0){
                    flag = 0;
                    break;
                }
            }
            
            num += flag;
            
        }
        
        return num;
    }
};