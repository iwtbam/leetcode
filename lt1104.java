import java.util.*;

class Solution {
    public List<Integer> pathInZigZagTree(int label) {
        List<Integer> res = new ArrayList<>();
        int deep = (int)(Math.log(label) / Math.log(2)) + 1;
        boolean flag = true, isContinue = true;
        while(deep >= 1){
            res.add(label);
            int end = (int)Math.pow(2, deep) - 1, start = (int)Math.pow(2, deep - 1);
            label = (start + (end - label)) / 2;
            deep--;
        }
        Collections.reverse(res);
        return res;
    }
}