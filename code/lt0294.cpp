// https://leetcode-cn.com/problems/flip-game-ii/
// flip game ii
class Solution {
public:
    unordered_map<string, bool> memos;

    bool canWin(string s) {
        if(memos.count(s) == 1)
            return memos[s];
        int size = s.size();
        for(int i = 0; i < size - 1; i++){
            if(s[i] == '+' && s[i + 1] == '+'){
                string temp = s;
                temp[i] = '-';
                temp[i + 1] = '-';
                bool res = canWin(temp);
                if(!res){
                    memos[s] = true;
                    return true;
                }
            }    
        }
        memos[s] = false;
        return false;
    }
};