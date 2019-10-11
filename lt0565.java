class Solution {
    public int arrayNesting(int[] nums) {
        int len = nums.length;
        if(len == 0)
            return 0;
        
        
        boolean[] visited = new boolean[len];
        int res = 0;
        for(int i = 0; i < len; i++){
            if(!visited[i]){
                visited[i] = true;
                int count = 1;
                int index = i;
                while(nums[index] < len && !visited[nums[index]]){
                    index = nums[index];
                    visited[index] = true;
                    count++;
                }
                
                res = Math.max(count, res);
            }
        }
        
        return res;
    }
}