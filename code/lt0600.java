
// 2019-10-20:20-17 暴力超时
// class Solution {
//     public int findIntegers(int num) {
//         helper(0, num);
//         return total;
//     }
    
//     public void helper(int cur, int num){
//         if(cur > num)
//             return;
//         total = total + 1;
//         if(cur!=0)
//             helper(cur << 1 | 0, num);
//         if((cur & 1) == 0)
//             helper(cur << 1 | 1, num);
//         return;
//     }
    
//     int total = 0;
// }