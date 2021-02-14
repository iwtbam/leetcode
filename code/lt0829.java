//2019-09-17:太真实, 太难了, 不细心,  逻辑差, 真在这一行混不出来
class Solution {
    public int consecutiveNumbersSum(int N) {
        
        int count = 0;
        int len = (int)Math.sqrt(N * 2);
        for(int k = 1; k <= len; k++){
            if((N * 2) % k == 0){
                int res = N * 2 / k - k - 1;
                if(res % 2 == 0 && res >= 0)
                    count++;
            }
        }   

        return count;
    }
}