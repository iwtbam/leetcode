// https://leetcode-cn.com/problems/palindrome-permutation-lcci/
// palindrome permutation lcci
class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> record(256, 0);
        size_t size = s.size();
        
        for(int i = 0; i < size; i++){
            record[s[i]]++;
        }

        int num = 0;

        for(int i = 0; i < 256; i++){
            num = num + record[i] % 2;
        }
        
        return num <= 1;
    }
};