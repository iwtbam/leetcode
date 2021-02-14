// https://leetcode-cn.com/problems/reverse-vowels-of-a-string/
// reverse vowels of a string
class Solution {
public:

    string reverseVowels(string s) {
        unordered_set<char> record = {'a', 'o', 'e', 'i', 'u', 'A', 'O', 'E', 'I', 'U'};
        int left = 0, right = s.size() - 1;
        while(left < right){
            while(left < right && record.count(s[left])==0)
                left++;
            while(left < right && record.count(s[right])==0)
                right--;
            
            if(left >= right)
                break;

            swap(s[left], s[right]);
            left++, right--;
        }
        return s;
    }
};