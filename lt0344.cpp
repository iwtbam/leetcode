// https://leetcode-cn.com/problems/reverse-string/
// reverse string
class Solution {
public:

    using IterType = vector<char>::iterator;

    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while(left < right)
        {
            swap(s.begin() + left, s.begin() + right);
            left++;
            right--;
        }
        return;
    }

    inline void swap(IterType&& i1, IterType&& i2)
    {
        *i1 = (*i1) ^ (*i2);
        *i2 = (*i1) ^ (*i2);
        *i1 = (*i1) ^ (*i2);
    }
};