// https://leetcode-cn.com/problems/replace-the-substring-for-balanced-string/
// replace the substring for balanced string
class Solution {
public:

    int balancedString(string s) {
        unordered_map<char, int> count = {};
        int size = s.size();
        for(int i = 0; i < size; i++)
            count[s[i]]++;

        if(check(count, size / 4))
            return 0;

        int right = 0, left = 0, res = size;
        while(right < size){
            char c = s[right];
            count[c]--;
            while(check(count, size / 4)){
                res = std::min(res, right - left + 1);
                count[s[left]]++;
                left++;
            }

            right++;
        }

        return res;
    }

    inline bool check(unordered_map<char, int>& count, int threshold){
        for(char c : "QWER"){
            if(count[c] > threshold)
                return false;
        }

        return true;
    }
};