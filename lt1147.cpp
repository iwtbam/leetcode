// https://leetcode-cn.com/problems/longest-chunked-palindrome-decomposition/
// longest chunked palindrome decomposition
class Solution {
public:
    int longestDecomposition(string text) {
        size_t size = text.size();
        string sl, sr;

        int i = 0, j = size - 1;
        int res = 0;
        while(i < j){
            sl.append(1, text[i]);
            sr.insert(0, 1, text[j]);
           // cout << sl << " " << sr << endl;
            if(sl == sr) {
                res = res + 2;
                sl = "";
                sr = "";
            }
            i++;
            j--;
        }

       
        return res + ((sl.size() || text.size() % 2 == 1) ? 1 : 0);
    }
};