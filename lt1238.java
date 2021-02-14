// https://leetcode-cn.com/problems/circular-permutation-in-binary-representation/
// circular permutation in binary representation
class Solution {
    public List<Integer> circularPermutation(int n, int start) {
        List<Integer> res = new ArrayList<>();
        int total = (int)Math.pow(2, n);
        int[] nums = new int[total];
        int offset = 0;
        for(int i = 0; i < total; i++){
            int num = i ^ i >> 1;
            if(num == start)
                offset = i;
            nums[i] = num;
        }

        for(int i = 0; i < total; i++)
            res.add(nums[(i + offset) % total]);
        return res;
    }
}