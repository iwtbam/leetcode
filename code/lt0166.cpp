// https://leetcode-cn.com/problems/fraction-to-recurring-decimal/
// fraction to recurring decimal
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long n = numerator;
        long long d = denominator;
        string sign = "";
        if(n * 1L * d < 0){
            sign = "-";
        } 
        n = abs(n);
        d = abs(d);

        string s = sign + to_string(n / d);
        
        if(n % d == 0)
            return s;
    
        n = n - n / d * d;
        string suffix = "";
        unordered_map<string, int> record;
        int cur = 0;
        string eq = to_string(n) + "/" + to_string(d);
        while(record.count(eq) == 0){
            record[eq] = cur++;
            n = n * 10;
            if(n < d){
                eq = to_string(n) + "/" + to_string(d);
                suffix.push_back('0');
                continue;
            }

            suffix += to_string(n / d);
            
            if(n % d == 0){
                return s + "." + suffix;
            }
            n = n - n / d * d;
            eq = to_string(n) + "/" + to_string(d);
        }

        suffix.insert(record[eq], "(");
        return s + "."  + suffix + ")";
    }
};