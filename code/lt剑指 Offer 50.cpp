// https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
// di yi ge zhi chu xian yi ci de zi fu lcof
class Solution {
public:
    char firstUniqChar(string s) {
        int arr[26] = {0};
        size_t size = s.size();
        for(int i = 0; i < size; i++){
            arr[s[i] - 'a']++;
        }
        for(int i = 0; i < size; i++){
            if(arr[s[i] - 'a'] == 1)
                return s[i];
        }
        return ' ';
    }
};