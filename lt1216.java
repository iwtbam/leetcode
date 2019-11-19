import java.util.*;

class Solution {
    public boolean isValidPalindrome(String s, int k) {
        int lo = 0, hi = s.length() - 1;
        return helper(s, lo, hi, k, 0);
    }
    
    public boolean helper(String s, int lo, int hi, int k, int c){
        long state = lo + hi * 1000 + c * 1000000;
        
        if(memos.get(state) != null)
            return memos.get(state);
        
        if(c > k){
            memos.put(state,  false);
            return false;
        }
        
        if(lo >= hi){
            memos.put(state, true);
            return true;
        }
        if(s.charAt(lo) == s.charAt(hi)){
            if(helper(s, lo + 1, hi - 1, k, c)){
                memos.put(state, true);
                return true;
            }
        }else{
        
            if(helper(s, lo + 1, hi, k, c + 1)){
                memos.put(state, true);
                return true;
            }
        
            if(helper(s, lo, hi - 1, k, c + 1)){
                memos.put(state, true);
                return true;
            }
        }
        
        memos.put(state,  false);
        
        return false;
    }
    
    private Map<Long, Boolean> memos = new HashMap<>();
}