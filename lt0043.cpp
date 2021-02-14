// https://leetcode-cn.com/problems/multiply-strings/
// multiply strings
class Solution {
public:
    string multiply(string num1, string num2) {

        if(num1 == "0" || num2 == "0")
            return "0";

        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());

        std::string res = {"0"};
        int size = num1.size();

        for(int i = 0; i < size; i++){
            res = add(res, multiply(num2, num1[i] - '0', i));
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

    string multiply(const string& num1, int c, int offset){
        string res = {};
        if(offset > 0){
            res = string(offset, '0');
        }

        int p = 0, co = 0, size = num1.size();
        while(p < size){
            int num = (num1[p] - '0') * c + co;
            co = num / 10;
            num = num % 10;
            res.push_back(num + '0');
            p++;
        }

        if(co > 0)
            res.push_back(co + '0');

        return move(res);
    }

    string add(const string& num1, const string&& num2){
        int size2 = num2.size();
        int size1 = num1.size();
        int min_size = std::min(size1, size2);
        int max_size = std::max(size1, size2);
        int p = 0, co = 0;

        string res = {};

        while(p < max_size){
            int n1 = p < size1 ? num1[p] - '0' : 0;
            int n2 = p < size2 ? num2[p] - '0' : 0;
            int num = n1 + n2 + co;
            co = num / 10;
            num = num % 10;
            res.push_back(num + '0');
            p++;
        }

        if(co!=0)
            res.push_back(co + '0');

        return move(res);
    }
};