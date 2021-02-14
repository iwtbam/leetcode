import java.util.*;

class Solution {
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal)
            return true;
        
        if(maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
            return false;
        
        return canWin(maxChoosableInteger, desiredTotal, 0, new HashMap<Integer, Boolean>());
    }
    
    public boolean canWin(int length, int nowTarget, int used, Map<Integer, Boolean> memos){
        if(memos.get(used)!=null)
            return memos.get(used);
        
        for(int i = 0; i < length; i++){
            int cur = (1 << i);
            if((cur & used) == 0){
                if(nowTarget <= i + 1 || !canWin(length, nowTarget - (i + 1), cur | used, memos)){
                    memos.put(used, true);
                    return true;
                }
            }
        }
        
        memos.put(used, false);
        return false;
    }
}