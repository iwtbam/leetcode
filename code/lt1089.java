// https://leetcode-cn.com/problems/duplicate-zeros/
// duplicate zeros
class Solution {
    public void duplicateZeros(int[] arr) {
        List<Integer> res= new ArrayList<>();
        for(int e:arr){
            res.add(e);
            if(e==0)
                res.add(0);
        }
        for(int i=0;i<arr.length;i++){
            arr[i]=res.get(i);
        }
    }
}