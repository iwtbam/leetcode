// https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
// zui chang bu han zhong fu zi fu de zi zi fu chuan lcof
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, len = 0, size = s.size();
        unordered_set<char> record;
        while(right < size){
            while(record.count(s[right])){
                record.erase(s[left]);
                left++;
            }
            len = max(len, right - left + 1);
            record.insert(s[right]);
            right++;
        }
        return len;
    }
};