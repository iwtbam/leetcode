// https://leetcode-cn.com/problems/thousand-separator/
// thousand separator
class Solution {
public:
    string thousandSeparator(int n) {
        
        if(n == 0)
            return "0";
        
        string s = "";
        
        while(n >= 1000){
            string part = to_string(n % 1000);
            part = string(3 - part.size(), '0') + part;
            s = "." + part + s;
            n /= 1000;
        }
        
        if(n != 0){
            s = to_string(n) + s;
        }
        
        return s;
        
    }
};