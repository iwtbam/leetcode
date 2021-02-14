// https://leetcode-cn.com/problems/print-words-vertically/
// print words vertically
class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> strs = {};
        int size = s.size();
        int start = 0;
        int cols = 0;
        for(int i = 0; i < size; i++){
            if(i == size - 1 || s[i]==' '){
                if(i == size - 1)
                    i = size;
                strs.push_back(s.substr(start, i - start));
                cols = max(cols, i - start);
                start = i + 1;
            }
        }
        
        vector<string> res = {};
        cout << cols << endl;
        int rows = strs.size();
        for(int i = 0; i < cols; i++){
            string temp = {};
            for(int j = 0; j < rows; j++){
                if(strs[j].size() <= i)
                    temp.push_back(' ');
                else
                    temp.push_back(strs[j][i]);
            }
            
            size = temp.size();
            int pos = size - 1;
            while(pos >= 0 && temp[pos]==' ')
                pos--;
            
            temp = temp.substr(0, pos + 1);
            
            res.push_back(temp);
        }
        
        return res;
    }
};