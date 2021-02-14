// https://leetcode-cn.com/problems/valid-number/
// valid number
class Solution {
public:
    bool isNumber(string s) {

        int point_flag = 0;
        int sign_flag = 1;
        int e_flag = 0;
        int after_point_num = 0;
        int after_e_num = 0;
        int num_flag = 0;
        int size = s.size();

        int left = 0, right = size - 1;

        while(left < size && s[left] == ' ')
            left++;
        while(right >= 0 && s[right] == ' ')
            right--;
        
        s = s.substr(left, right - left + 1);
        size = s.size();
        char ec = s[size - 1];
        if(size == 0 || ec == 'e' || ec == '+' || ec == '-')
            return false;

        for(int i = 0; i < size; i++){
            char c = s[i];
            if(sign_flag && (c == '+' || c == '-')){
                sign_flag = 0;
                continue;
            }

            sign_flag = 0;

            if(c == '.' && point_flag == 0 && e_flag == 0){
                point_flag = 1;
                continue;
            }

            if(c == 'e' && i!=0 && e_flag!=1 && num_flag!=0){
                sign_flag = 1;
                e_flag = 1;
                continue;
            }

            if(c < '0' || c > '9')
                return false;

            num_flag++;
        }   

        if(num_flag == 0)
            return false;

        return true;
    }
};