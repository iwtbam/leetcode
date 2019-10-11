import java.util.*;

class Solution {
    public boolean judgePoint24(int[] nums) {
        List<Double> numsList = new ArrayList<>();
        for(int i = 0; i < nums.length; i++)
            numsList.add((double)nums[i]);
        return judgePoint24(numsList);
    }
    
    public boolean judgePoint24(List<Double> nums){
            
        if(nums.size() == 1){
            return Math.abs(nums.get(0) - 24) <= err;
        }
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                if(i == j)
                    continue;
                
                List<Double> next = new ArrayList<>();
                
                for(int k = 0; k < nums.size(); k++){
                    if(k!=i && k!=j)
                        next.add(nums.get(k));
                }
                
                
                for(int op = 0; op < 4; op++){
                    if(op < 2 && j < i)
                        continue;
                    
                    switch(op){
                        case 0:
                            next.add(nums.get(i) + nums.get(j));
                            break;
                        case 1:
                            next.add(nums.get(i) * nums.get(j));
                            break;
                        case 2:
                            next.add(nums.get(i) - nums.get(j));
                            break;
                        case 3:
                            if(nums.get(j)!=0)
                                next.add(nums.get(i) / nums.get(j));
                            else
                                continue;
                    }
                
                    if(judgePoint24(next))
                        return true;
                    next.remove(next.size() - 1);
                }
                
            }
        }   
        return false;
    }    
    private final double err = 0.0001;
}