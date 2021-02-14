// https://leetcode-cn.com/problems/find-smallest-letter-greater-than-target/
// find smallest letter greater than target
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size();
        while(l < r){
            int mid = (l + r) >> 1;
            if(letters[mid] > target){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l == letters.size() ? letters[0] : letters[l];
    }

    
};