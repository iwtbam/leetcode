// https://leetcode-cn.com/problems/is-unique-lcci/
// is unique lcci
class Solution {
public:
    bool isUnique(string astr) {
        if(astr.size() == 0)
            return true;
        sort(astr.begin(),astr.end());
        size_t size = astr.size();
        for(int i = 0; i < size - 1; i++){
            if(astr[i] == astr[i + 1])
                return false;
        }
        return true;
    }
};