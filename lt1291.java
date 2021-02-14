// https://leetcode-cn.com/problems/sequential-digits/
// sequential digits
class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> temp = new ArrayList<>();
        
        for(int i = 0;  i < 8; i++){
            for(int j = 0; j <= num[i]; j++){
                int num = start[i] + inc[i] * j;
                if(num > high)
                    break;
                if(num >= low)
                    temp.add(num);
            }
        }
        
        return temp;
    }
    
  
    
    private final int[] start = {12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789};
    private final int[] inc   = {11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};
    private final int[] num   = {7,  6,   5,    4,     3,      2,       1,        0};
}