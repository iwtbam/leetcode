// https://leetcode-cn.com/problems/element-appearing-more-than-25-in-sorted-array/
// element appearing more than 25 in sorted array
class Solution {
    public int findSpecialInteger(int[] arr) {
        int[] count = new int[100001];
        int L = arr.length;
        int t = (int)Math.floor(L * 0.25) + 1;
        for(int i = 0; i < L; i++){
            count[arr[i]]++;
            if(count[arr[i]] >= t)
                return arr[i];
        }
        
        return -1;
    }
}