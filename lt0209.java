// https://leetcode-cn.com/problems/minimum-size-subarray-sum/
// minimum size subarray sum
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int L = nums.length; 
        int[] sums = new int[L + 1];
        for(int i = 1; i <= L; i++)
            sums[i] = sums[i - 1] + nums[i - 1];
        int minL = L + 1;
        for(int i = 0; i < L; i++){
            int sp = search(sums, -1, i - 1, sums[i + 1] - s);
            // System.out.println(i + " " + sp);            
            if(sp != -2 &&sums[i + 1] - sums[sp + 1] >= s){
                minL = Math.min(minL, i - sp);
            }
        }

        return minL == L + 1 ? 0 : minL;
    }

    public int search(int[] sums, int s, int e, int target){
        while(s < e){
            int mid = (s + e) / 2;

            // System.out.println(s + " " + mid + " " + e);
            if(sums[mid + 1] > target)
                e = mid - 1;
            else
                s = mid + 1;
        }

        return sums[s + 1] > target ? s - 1 : s;
    }


}