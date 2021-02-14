// https://leetcode-cn.com/problems/lemonade-change/
// lemonade change
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int size = bills.size();
        for(int i = 0; i < size; i++){
            int bill = bills[i];
            if(bill == 5){
                five++;
            }
            if(bill == 10){
                if(five <= 0)
                    return false;
                five--;
                ten++;
            }
            if(bill == 20){
                int pay = 15;
                if(ten > 0){
                    ten--;
                    pay -= 10;
                }
                if(pay / 5 > five){
                    return false;
                }
                five -= pay / 5;
            }
        }
        return true;
    }
};