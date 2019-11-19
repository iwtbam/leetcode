import java.util.*;

class Solution {
    public List<Integer> minAvailableDuration(int[][] slots1, int[][] slots2, int duration) {
        List<Integer> arrs = new ArrayList<>();
        int i = 0, j = 0;
        int l1 = slots1.length, l2 = slots2.length;
        
        Arrays.sort(slots1, new Comparator<int[]>(){
           public int compare(int[] e1, int[] e2){
               return e1[0] - e2[0] == 0 ? e1[1] - e2[1] : e1[0] - e2[0];
           } 
        });
        
        
        Arrays.sort(slots2, new Comparator<int[]>(){
           public int compare(int[] e1, int[] e2){
               return e1[0] - e2[0] == 0 ? e1[1] - e2[1] : e1[0] - e2[0];
           } 
        });
        
        
        while(i < l1 && j < l2){
            int[] slot1 = slots1[i];
            int[] slot2 = slots2[j];
            
            if(slot1[0] >= slot2[1]){
                j++;
                continue;
            }
            
            if(slot2[0] >= slot1[1]){
                i++;
                continue;
            }
            
            if(slot1[1] > slot2[1])
                j++;
            else if(slot1[1] < slot2[1])
                i++;
            else{
                i++;
                j++;
            }
            
            int start = Math.max(slot1[0], slot2[0]);
            int end = Math.min(slot1[1], slot2[1]);
            
            // System.out.println(start);
            if(end - start >= duration){
                arrs.add(start);
                arrs.add(start + duration);
                return arrs;
            }
        }
        
        return arrs;
    }
}