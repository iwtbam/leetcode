// https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/
// ba zi fu chuan zhuan huan cheng zheng shu lcof
class Solution {
public:
    int strToInt(string str) {
        size_t size = str.size();
        if(size == 0)
            return 0;
        int start = 0, end = size - 1;
        while(start <= end && str[start] == ' ')
            start++;
        while(end >= start && str[end] == ' ')
            end--;

        long long val = 0;
        int sign = 1;
        for(int i = start; i <= end; i++){
            if(str[i] < '0' || str[i] > '9'){
                if(i == start && (str[i] == '+' || str[i] == '-')){
                    if(str[i] == '-')
                        sign = -1;
                    continue;
                }
                return val * sign;
            }
            val = val * 10 + str[i] - '0';
            if(val > INT_MAX && sign == 1)
                return INT_MAX;
            if(sign == -1 && val > INT_MAX + 1L)
                return INT_MIN;
        }
        return sign * val;
    }
};