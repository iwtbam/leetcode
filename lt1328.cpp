// https://leetcode-cn.com/problems/break-a-palindrome/
// break a palindrome
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int size = palindrome.size();
        if(size == 1)
            return "";
        int half = size / 2;
        for(int i = 0; i < half; i++){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        palindrome[size - 1] = 'b';
        return palindrome;
    }
};