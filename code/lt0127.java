
import javafx.util.Pair;
import java.util.*;

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        int len = beginWord.length();
        
        if(!wordList.contains(endWord))
            return 0;
        
        Map<String, List<String>> graph = new HashMap<>();
        
        wordList.forEach(
            word -> {
                for(int i = 0; i < len; i++){
                    String key = word.substring(0, i) + "*" + word.substring(i + 1, len);
                    if(!graph.containsKey(key))
                        graph.put(key, new ArrayList<>());
                    graph.get(key).add(word);
                }
            }
        );
        
        Queue<Pair<String, Integer>> q = new LinkedList<>();
        List<String> empty = new ArrayList<>();
        Set<String> vis = new HashSet<>();
        vis.add(beginWord);
        q.offer(new Pair(beginWord, 1));
        
        while(q.size() > 0){
            Pair<String, Integer> top = q.poll();
            String word = top.getKey();
            int dis = top.getValue();
            for(int i = 0; i < len; i++){
                String key = word.substring(0, i) + "*" + word.substring(i + 1, len);
                for(String next : graph.getOrDefault(key, empty)){
                    if(next.equals(endWord))
                        return dis + 1;
                    
                    if(vis.contains(next))
                        continue;
                    
                    q.offer(new Pair(next, dis + 1));
                    vis.add(next);
                }
            }
        }
        
        return 0;
    }
    
}


// 2019-10-01:21-05 DFS 超时
// class Solution {
//     public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        
//         if(!wordList.contains(endWord))
//             return 0;
        
//         boolean[] vis = new boolean[wordList.size()];
//         int step = helper(beginWord, endWord, wordList, vis, 1);
//         return step == UN_SOLVED ? 0 : step;
//     }
    
//     public int helper(String cur, String end, List<String> wordList, boolean[] vis, int step){

        
//         if(cur.equals(end))
//             return step;
        
        
        
//         int minStep = UN_SOLVED;
        
//         for(int i = 0; i < wordList.size(); i++){
//             if(vis[i])
//                 continue;
            
//             if(!isNext(cur, wordList.get(i)))
//                 continue;
            
//             vis[i] = true;
//             minStep = Math.min(minStep, helper(wordList.get(i), end, wordList, vis, step + 1));
//             vis[i] = false;
//         }
        
        
//         return minStep;
//     }
    
//     public boolean isNext(String cur, String next){
//         int count = 0;
//         for(int i = 0; i < cur.length(); i++)
//             if(cur.charAt(i) != next.charAt(i))
//                 count++;
//         return count == 1;
//     }
    
//     private final int UN_SOLVED = Integer.MAX_VALUE;
// }