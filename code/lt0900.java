import java.util.*;

class RLEIterator {

    class Node {
        int val;
        int num;
        Node(int num, int val){
            this.val = val;
            this.num = num;
        }
    }
    
    public RLEIterator(int[] A) {
        int len = A.length;
        for(int i = 0; i < len; i += 2){
            if(A[i] == 0)
                continue;
              q.offer(new Node(A[i], A[i + 1]));
        }
    }
    
    public int next(int n) {
        int target = -1;
        while(n > 0 && q.size() > 0){
            Node top = q.peek();
            if(top.num > n){
              
                top.num = top.num - n;
                n = 0;
            }else{
                n -= top.num;
                top.num = 0;
            }
            
          
            if(n == 0)
                target = top.val;
            
            if(top.num == 0)
                q.poll();
        }
        
        return target;
    }
    
    private Queue<Node> q = new LinkedList<>();
}

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */