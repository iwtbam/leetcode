// https://leetcode-cn.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
// number of steps to reduce a number in binary representation to one
class Solution {
public:
    int numSteps(string s) {
        string target = "1";
        int step = 0;
        while(s != target){
            if(s[s.size() - 1] == '0'){
                s = s.substr(0, s.size() - 1);
            }else{
                int size = s.size();
                int i = size - 1;
                for(; i >= 0; i--){
                    if(s[i] == '0'){
                        s[i] = '1';
                        break;
                    }
                    s[i] = '0';
                }
                if(i < 0){
                    s = "1" + s;
                }
            }
            cout << s << endl;
            step++;
        }
        
        return step;
    }
};