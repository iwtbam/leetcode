import java.util.*;

class Solution {
    public int largestValsFromLabels(int[] values, int[] labels, int num_wanted, int use_limit) {
        int len = values.length;
        
        if(len == 0)
            return 0;
        
        int[][] record = new int[len][2];
        
        for(int i = 0; i < len; i++){
            record[i][0] = values[i];
            record[i][1] = labels[i];
        }
                
        Arrays.sort(record, new Comparator<int[]>(){
            public int compare(int[] a, int[] b){
                return b[0] - a[0];
            } 
        });
        
        
        int sum = 0;
        
        Map<Integer, Integer> memos = new HashMap<>();
        
        for(int i = 0; i < len && num_wanted > 0; i++){
            
            Integer cur_num = memos.get(record[i][1]);    
            if(cur_num == null)
                memos.put(record[i][1], 1);
            else
                memos.put(record[i][1], cur_num + 1);
            
            if(memos.get(record[i][1]) <= use_limit){
                sum += record[i][0];
                num_wanted--;
            }
        }

        return sum;
    }
    
}