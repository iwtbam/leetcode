#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        int count[26] = {0};
        int max_cnt = INT_MIN;
        while(right < s.size())
        {
            count[s[right] - 'A']++;
            max_cnt = max(count[s[right] - 'A'], max_cnt);
            if(right - left - max_cnt + 1 > k)
                count[s[left++] - 'A']--;
            right++;
        }

        return max_cnt + k > s.size() ? s.size() : max_cnt + k;      
    }
};