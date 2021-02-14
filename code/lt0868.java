// https://leetcode-cn.com/problems/binary-gap/
// binary gap
class Solution {
    public int binaryGap(int N) {
        int pre = -1;
        int dis = 0;
        int pos = 0;
        while(N > 0){
            if(N % 2 == 1){
                if(pre!=-1){
                    dis = Math.max(dis, pos - pre);
                }
                pre = pos;
            }

            N /= 2;

            pos++;
        }

        return dis;
    }
}