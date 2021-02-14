// https://leetcode-cn.com/problems/largest-unique-number/
// largest unique number
class Solution {
    public int largestUniqueNumber(int[] A) {
        int[] record = new int[1001];
        for(int num : A){
            record[num]++;
        }
        for(int i = 1000; i >= 0; i--){
            if(record[i] == 1)
                return i;
        }

        return -1;
    }
}