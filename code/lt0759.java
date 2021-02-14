// https://leetcode-cn.com/problems/employee-free-time/
// employee free time
/*
// Definition for an Interval.
class Interval {
    public int start;
    public int end;

    public Interval() {}

    public Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
    public List<Interval> employeeFreeTime(List<List<Interval>> schedule) {
        List<Interval> res = new ArrayList<>();
        res.add(new Interval(-inf, inf));

        for(List<Interval> il : schedule){
            int left = -inf;
            List<Interval> cur = new ArrayList<>();
            int size = res.size(); 
            il.add(new Interval(inf, inf));
            for(Interval it : il){
                int right = it.start;
                // System.out.print("[" + left + " " + right + "]");
                for(int i = 0; i < size; i++){
                    if(right <= res.get(i).start)
                        break;
                    if(left >= res.get(i).end)
                        continue;
                    cur.add(new Interval(Math.max(left, res.get(i).start), Math.min(right, res.get(i).end)));
                }
                left = it.end;
            }
            // System.out.println();
            res = cur;
        }
        res.remove(res.size() - 1);
        res.remove(0);
        return res;    
    }

    private final int inf = Integer.MAX_VALUE / 2;
}