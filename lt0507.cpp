// https://leetcode-cn.com/problems/perfect-number/
// perfect number
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 1)
            return false;
        
        int sum = 0;

        int half = sqrt(num);
        for(int i = 1; i <= half; i++){
            if(num % i == 0 ){
                if(i!=num)
                    sum += i;
                // cout << i << " " << (num / i) << endl;
                if(num / i != i && num /i != num)
                    sum += num / i;
            }
        }

        return sum == num;
    }
};