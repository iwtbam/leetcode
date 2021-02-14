// https://leetcode-cn.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
// divide array in sets of k consecutive numbers
class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        Map<Integer, Integer> record = new HashMap<>();
        Set<Integer> lookup = new TreeSet<>();
        int L = nums.length;
        for(int i = 0; i < L; i++){
            record.put(nums[i], record.getOrDefault(nums[i], 0) + 1);
            lookup.add(nums[i]);
        }
        
        for(int num : lookup){
            int count = record.get(num);
            if(count == 0)
                continue;
            
            for(int i = 1; i < k; i++){
             
                Integer temp = record.get(i + num);
                if(temp == null)
                    return false;
                
                if(temp < count)
                    return false;
                record.put(i + num, temp - count);
            }
            
            
        }
        
        return true;
    }
}