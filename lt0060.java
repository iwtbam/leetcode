// https://leetcode-cn.com/problems/permutation-sequence/
// permutation sequence
class Solution {
    public String getPermutation(int n, int k) {
        int[] fact = new int[n];
        List<Integer> nums = new ArrayList<>();
        nums.add(1);
        fact[0] = 1;
        
        for(int i = 1; i < n; i++){
            fact[i] = fact[i - 1] * i;
            nums.add(i + 1);
        }

        StringBuilder sb = new StringBuilder();
        k--;

        for(int i = n - 1; i >= 0; i--){
            int index = k / fact[i];
            k = k - index * fact[i];
            sb.append(nums.get(index));
            nums.remove(index);
        }

        return sb.toString();
    }
}