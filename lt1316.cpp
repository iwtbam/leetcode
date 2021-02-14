// https://leetcode-cn.com/problems/distinct-echo-substrings/
// distinct echo substrings
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int size = text.size();
        unordered_set<string> count = {};
        for(int i = 0; i < size; i++){
            int offset = 0, start = i + 1;
            for(int j = i + 1; j < size; j++){
                // if(text[j] != text[i + offset]){
                //     offset = 0;
                //     start = j + 1;
                // }else{
                //     offset++;
                //     if(i + offset == start){
                //         count.insert(text.substr(i, offset * 2));
                //         cout << text.substr(i, offset * 2) << endl;
                //         offset = 0;
                //         start = j + 1;
                //     }
                // }
                
                if(text[j] != text[i])
                    continue;
                
                offset = j - i;
                if(j + offset > size)
                    break;
                
                int k = 0;
                
                for(; k < offset; k++){
                    if(text[i + k] != text[j + k])
                        break;
                }
                
                if(k == j - i){
                    count.insert(text.substr(i,  offset * 2));
                }
            }
        }
        
        return count.size();
    }
};