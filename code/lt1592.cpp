// https://leetcode-cn.com/problems/rearrange-spaces-between-words/
// rearrange spaces between words
class Solution {
public:
    string reorderSpaces(string text) {
        int space = 0;
        size_t size = text.size();
        for(int i = 0; i < size; i++)
            if(text[i] == ' ')
                space++;
        stringstream ss(text);
        
        vector<string> strs;
        string data;
        while(ss >> data){
            strs.push_back(data);
        }
        
        int ws = strs.size();
        int count = 0;

        if(ws > 1)
            count = space / (ws - 1);        
        
        int mod = space - count * (ws - 1);
        string res;
        
        for(int i = 0; i < ws - 1; i++)
            res = res + strs[i] + string(count, ' ');
        res = res + strs.back() + string(mod, ' ');
        
        return res;
    }
};