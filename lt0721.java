import java.util.*;

class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        int emailId = 0;
        Map<String, Integer> emailIds = new HashMap<>();
        Map<String, String> names = new HashMap<>();
        DUS dus = new DUS();
        for(List<String> account : accounts){
            int size = account.size();
            String name = account.get(0);
            for(int i = 1; i < size; i++){
                String email = account.get(i);
                if(!emailIds.containsKey(email)){
                    emailIds.put(email, emailId++);
                }
                names.put(email, name);
                dus.merge(emailIds.get(account.get(1)), emailIds.get(email));
            }
        }

        Map<Integer, List<String>> emails = new HashMap<>();
        for(Map.Entry<String, Integer> entry : emailIds.entrySet()){
            String key = entry.getKey();
            Integer val = dus.parent(entry.getValue());
            // System.out.println(val);
            if(!emails.containsKey(val))
                emails.put(val, new ArrayList<>());
            emails.get(val).add(key);
        }

        List<List<String>> res = new ArrayList<>();

        for(List<String> val : emails.values()){
            Collections.sort(val);
            val.add(0, names.get(val.get(0)));
            res.add(val);
        }

        return res;
    }
}

class DUS {
    private int[] sets = new int[10001];
    private int[] ranks = new int[10001];

    public DUS() {
        for(int i = 0; i < sets.length; i++)
            sets[i] = i;
    }

    public int parent(int n){
        return sets[n] == n ? n : parent(sets[n]);
    }

    public boolean merge(int n1, int n2){
        int p1 = parent(n1);
        int p2 = parent(n2);
        if(p1 == p2)
            return false;

        if(ranks[p1] < ranks[p2]){
            sets[p1] = p2;
        }else{
            if(ranks[p1] == ranks[p2])
                ranks[p1]++;
            sets[p2] = p1;
        }
        return true;
    }
}