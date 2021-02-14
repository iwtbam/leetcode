// https://leetcode-cn.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
// minimum flips to make a or b equal to c
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        for(int i = 0; i < 32; i++){
            bool c1 = c & (1 << i);
            bool b1 = b & (1 << i);
            bool a1 = a & (1 << i);
            if(c1 && !(b1 || a1))
                count++;
            
            if(!c1){
                if(b1)
                    count++;
                if(a1)
                    count++;
            }
            
        
        }
        
        return count;
    }
};