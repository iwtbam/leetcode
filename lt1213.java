import java.util.*;

class Solution {
    public List<Integer> arraysIntersection(int[] arr1, int[] arr2, int[] arr3) {
        List<Integer> res = new ArrayList<Integer>();
        int i1 = 0, i2 = 0, i3 = 0;
        int l1 = arr1.length, l2 = arr2.length, l3 = arr3.length;
        
        while(i1 < l1 && i2 < l2 && i3 < l3){
            int min = Math.min(arr1[i1], Math.min(arr2[i2], arr3[i3]));
            
            if(arr1[i1] == arr2[i2] && arr2[i2] == arr3[i3]){
                res.add(arr1[i1]);
            }
                        
            if(min == arr1[i1])
                i1++;
            
            if(min == arr2[i2])
                i2++;
            
            if(min == arr3[i3])
                i3++;
            
          
        }
        
        return res;
    }
}