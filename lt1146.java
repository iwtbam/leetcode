import java.util.*;

//2019-11-12:21-46 不优

class SnapshotArray {

    public SnapshotArray(int length) {
        arrays = new int[length];
    }
    
    public void set(int index, int val) {
        if(snaps.get(index)== null)
            snaps.put(index, new ArrayList<>());
        snaps.get(index).add(new int[]{snap_cur_id, arrays[index]});
        arrays[index] = val;
    }
    
    public int snap() {
        return snap_cur_id++;
    }
    
    public int get(int index, int snap_id) {
        if(!snaps.containsKey(index))
            return arrays[index];
        else{
            List<int[]> ops = snaps.get(index);
            int size = ops.size();
            for(int i = 0; i < size; i++){
                int[] op = ops.get(i);
                if(op[0] > snap_id)
                    return op[1];
            }
            return arrays[index];
        }
    }

    private int[] arrays = null;
    private int snap_cur_id = 0;
    private Map<Integer, List<int[]>> snaps = new HashMap<>();
}
