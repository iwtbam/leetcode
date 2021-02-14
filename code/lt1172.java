import java.util.*;

class DinnerPlates {

    public DinnerPlates(int capacity) {
        this.cap = capacity;
    }
    
    public void push(int val) {
        Iterator<Integer> it = emptys.iterator();
        if(!it.hasNext()){
            stacks.add(new Stack<Integer>());
            emptys.add(stacks.size() - 1);
            it = emptys.iterator();
        }
        Integer index = it.next();  
        stacks.get(index).push(val);
        if(stacks.get(index).size() == cap){
            emptys.remove(index);
        }
    }
    
    public int pop() {
        return popAtStack(stacks.size() - 1);
    }
    
    public int popAtStack(int index) {
        System.out.println("pop");
        if(index < 0 || index > stacks.size() - 1)
            return -1;

        Stack<Integer> curStack = stacks.get(index);
        if(curStack.empty())
            return -1;

        int res = curStack.pop();
        int last = stacks.size() - 1;
        while(last >= 0 && stacks.get(last).empty()){
            if(emptys.contains(last))
                emptys.remove(last);
            stacks.remove(last);
            last--;
        }

        if(index <= last){
            emptys.add(index);
        }

        return res;
    }

    private Set<Integer> emptys = new TreeSet<>();
    private List<Stack<Integer>> stacks = new ArrayList<>();
    private int cap = 0;
}