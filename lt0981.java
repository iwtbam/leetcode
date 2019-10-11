import java.util.*;

class TimeMap {

    /** Initialize your data structure here. */
    public TimeMap() {
        
    }
    
    public void set(String key, String value, int timestamp) {
        if(!stor.containsKey(key))
            stor.put(key, new TreeMap<Integer, String>());
        stor.get(key).put(timestamp, value);
    }
    
    public String get(String key, int timestamp) {
        if(!stor.containsKey(key))
            return new String();
        TreeMap<Integer, String> val = (TreeMap)stor.get(key);
        if(val.containsKey(timestamp))
            return val.get(timestamp);
        Integer pre = val.floorKey(timestamp);
        if(pre == null)
            return new String();
        return val.get(pre);
    }
    
    private Map<String, Map<Integer, String>> stor = new HashMap<>();
}
