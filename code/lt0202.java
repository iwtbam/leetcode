import java.util.HashMap;
import java.util.HashSet;

class Solution {
    public boolean isHappy(int n){
        HashSet<Integer> record = new HashSet<>();
        while(!record.contains(n)){
            record.add(n);
            n = calc(n);
            if(n == 1)
                return true;
        }
        return false;
    }

    public int calc(int n){
        int sum = 0;
        while(n != 0){
            sum += Math.pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
}