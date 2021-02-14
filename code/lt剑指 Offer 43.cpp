// https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/
// 1nzheng shu zhong 1chu xian de ci shu lcof
class Solution {
public:
    int countDigitOne(int n) {
        int low = 0, high = n / 10, cur = n % 10, ans = 0;
        long long t = 1;
        
        while(high != 0 || cur != 0){
            if(cur == 0){
                ans += high * t;
            }else if(cur == 1){
                ans += high * t + low + 1;
            }else{
                ans += (high + 1) * t;
            } 

            low = cur * t + low;
            t = t * 10;
            cur = high % 10;
            high = high / 10;
        }

        return ans;
    }
};