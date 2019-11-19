import java.util.*;


//2019-10-23:10-11
class Solution {
    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
     
        if(memos.get(needs)!=null)
            return memos.get(needs);
        
        int cost = Integer.MAX_VALUE;
        for(int i = 0; i < price.size(); i++){
            if(needs.get(i) == 0)
                continue;
            needs.set(i, needs.get(i) - 1);
            cost = Math.min(cost , shoppingOffers(price, special, needs) + price.get(i));
            needs.set(i, needs.get(i) + 1);
        }
        
        for(int i = 0; i < special.size(); i++){
            List<Integer> sp = special.get(i);
            if(!less(sp, needs))
                continue;
            minus(sp, needs);
            cost = Math.min(cost, shoppingOffers(price, special, needs) + sp.get(sp.size() - 1));
            add(sp, needs);
        }
        
        cost =  cost == Integer.MAX_VALUE ? 0 : cost;
        memos.put(needs, cost);
        return cost;
    }
    
    public boolean less(List<Integer> sp, List<Integer> needs){
        int size = needs.size();
        for(int i = 0; i < size; i++){
            if(sp.get(i) > needs.get(i))
                return false;
        }
        return true;
    }
    
    public void add(List<Integer> sp, List<Integer> needs){
        int size = needs.size();
        for(int i = 0; i < size; i++){
            needs.set(i, needs.get(i) + sp.get(i));
        }
    }
    
    public void minus(List<Integer> sp, List<Integer> needs){
        int size = needs.size();
        for(int i = 0; i < size; i++){
            needs.set(i, needs.get(i) - sp.get(i));
        }
    }
    
    private Map<List<Integer>, Integer> memos = new HashMap<>();
    
}