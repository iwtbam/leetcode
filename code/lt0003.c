// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
// longest substring without repeating characters
#define max_t(a, b) (a) > (b) ? (a) : (b)

int lengthOfLongestSubstring(char* s) {
    int pos[128], len = 0;
    memset(pos, 0, sizeof(pos));
    int size = strlen(s);
    for(int i =0, j = 0; j < size; j++){
        i = max_t(pos[s[j]], i);
        len = max_t(len, j - i + 1);
        pos[s[j]] =  j + 1;
    }
    return len;
}