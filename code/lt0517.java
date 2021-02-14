class Solution {
    public int findMinMoves(int[] machines) {
        int len = machines.length;
        if(len == 0)
            return 0;
        int total = 0;
        for(int clothes : machines)
            total += clothes;
        if(total % len != 0)
            return -1;
        
        int avg = total / len;
        int balance = 0, res = 0;
        for(int clothes : machines){
            balance += clothes - avg;
            res = Math.max(res, Math.max(Math.abs(balance), clothes - avg));
        }
        
        return res;
    }
}