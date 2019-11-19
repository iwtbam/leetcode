import java.util.*;

class Solution {
    public int minAreaRect(int[][] points) {
        Map<Integer, List<Integer>> rows = new TreeMap<>();
        for(int[] point : points){
            int x = point[0];
            int y = point[1];
            rows.computeIfAbsent(x, z -> new ArrayList<>()).add(y);
        }
        
        Map<Integer, Integer>  cols = new HashMap<>();
        int area = Integer.MAX_VALUE;
        for(int x : rows.keySet()){
            List<Integer> row = rows.get(x);
            Collections.sort(row);
            for(int i = 0; i < row.size(); i++){
                for(int j = i + 1; j < row.size(); j++){
                    int y1 = row.get(i);
                    int y2 = row.get(j);
                    int code = y1 * 40001 + y2;
                    if(cols.containsKey(code)){
                        area = Math.min(area, (x - cols.get(code)) * (y2 - y1));
                    }
                    cols.put(code, x);
                }
            }
        }
        
        return area == Integer.MAX_VALUE ? 0 : area;
    }
}