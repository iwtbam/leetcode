import java.util.*;

class Solution {
    public int longestSubsequence(int[] arr, int difference) {
        Map<Integer, ArrayList<Integer>> record = new HashMap<>();
        
        // for(int i = 0; i < arr.length; i++){
        //     if(!record.containsKey(arr[i]))
        //         record.put(arr[i], new ArrayList<Integer>());
        //     record.get(arr[i]).add(i);
        // }
        
        int len = arr.length;
        
        int[] dp = new int[len];
        
        Arrays.fill(dp, 1);
        
        for(int i = 1; i < len; i++){
            
            if(!record.containsKey(arr[i - 1]))
                record.put(arr[i - 1], new ArrayList<Integer>());
            
            record.get(arr[i - 1]).add(i - 1);
            
            if(record.containsKey(arr[i] - difference)){
                List<Integer> indexs = record.get(arr[i] - difference);
                for(int index : indexs){
                    dp[i] = Math.max(dp[i], dp[index] + 1);   
                }
//                 for(int index : indexs){
//                     System.out.println(index + " " + indexs[i]);
//                 }
//                 System.out.println(i + " " + dp[i]);
                
            }
        }
        
        int maxLen = 0;
    
        for(int i = 0; i < len; i++){
            maxLen = Math.max(maxLen, dp[i]);
            // if(maxLen == 3)
            //     System.out.println(i);
        }
       
        
        return maxLen;
    }
        
        
}