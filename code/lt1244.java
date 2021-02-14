import java.util.*;

class Leaderboard {

    public Leaderboard() {
        
    }
    
    public void addScore(int playerId, int score) {
        int pos = find(playerId);
        if(pos == -1)
            containers.add(new int[]{playerId, score});
        else{
            int[] target = containers.get(pos);
            target[1] = target[1] + score;
        }
            
    }
    
    public int top(int K) {
        Collections.sort(containers, (arr1, arr2) ->{
            return arr2[1] - arr1[1];
        });
        
        int sum = 0;
        
        for(int i = 0; i < K; i++)
            sum += containers.get(i)[1];
        
        return sum;
    }
    
    public void reset(int playerId) {
        int pos = find(playerId);
        if(pos == -1)
            return;
        containers.remove(pos);
    }
    
    private int find(int playerId){
        
        for(int i = 0; i < containers.size(); i++){
            if(containers.get(i)[0] == playerId)
                return i;
        }
        return -1;
    }
    
    private List<int[]> containers = new ArrayList<>();
}

