import java.util.*;

class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        
        if(nums2.length == 0 || nums1.length == 0)
            return new int[0];
        
        Map<Integer, Integer> record = new HashMap<>();
        int l2 = nums2.length;
        record.put(nums2[l2 - 1], -1);
        for(int i = l2 - 2; i >= 0; i--){
            if(nums2[i] < nums2[i+1])
                record.put(nums2[i], nums2[i+1]);
            else{
                int pre = nums2[i+1];
             
                while(record.get(pre) != -1 && record.get(pre) < nums2[i]){
                    pre = record.get(pre);
                }
                record.put(nums2[i], record.get(pre));
            }
        }
        
        int l1 = nums1.length;
        int[] res = new int[l1];
        
        for(int i = 0; i < l1; i++)
            res[i] = record.get(nums1[i]);
        
        return res;
    }
}