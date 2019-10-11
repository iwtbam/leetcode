class Solution {
    public int dietPlanPerformance(int[] calories, int k, int lower, int upper) {
        int len = calories.length;
        int[] record = new int[len];
        
        for(int i = 0; i < k && i < len; i++)
            record[0] += calories[i];
        
        for(int i = 1; i <= len - k; i++){
            record[i] = record[i - 1] - calories[i - 1] + calories[i + k - 1];
        }
        
        int scores = 0;
        
        for(int i = 0; i <= len - k; i++){
            
            if(record[i] < lower)
                scores = scores - 1;
            
            if(record[i] > upper)
                scores = scores + 1;
        }
        
        return scores;
    }
}