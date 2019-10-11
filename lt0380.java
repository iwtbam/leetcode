import java.util.*;

class RandomizedSet {

    /** Initialize your data structure here. */
    public RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if(con.contains(val))
            return false;
        con.add(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if(con.contains(val)){
            con.remove(val);
            return true;
        }
        
        return false;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        Integer[] arr = con.toArray(new Integer[]{1});
        int index = new Random().nextInt(arr.length);
        return arr[index];
    }
    
    private Set<Integer> con = new HashSet<>();
}