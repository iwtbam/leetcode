// https://leetcode-cn.com/problems/remove-palindromic-subsequences/
// remove palindromic subsequences
class Solution {
    public:
    int removePalindromeSub(string s) {
        int size = s.size();
        vector<int> used(size, 0);
        int count = 0;
        int num = 0;
        int left = 0;
        while(num < size){
            int right = size - 1;
            while(left <= right){
                if(used[right] || s[left] != s[right]){
                    right--;
                    continue;
                }
                right--;
                left++;
                if(left!=right)
                    num++;
                num++;
            }
            count++;
        }
        
        return count;
        
    }
};