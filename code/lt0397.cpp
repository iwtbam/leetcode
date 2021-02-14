class Solution {
public:
    int integerReplacement(int n) {
        int step = 0;
        long long ln = static_cast<long long>(n);
        while(ln!=1){
            if((ln & 3) == 3 && ln!=3)
                ln+=1;
            else if((ln & 1) == 1)
                ln-=1;
            else
                ln>>=1;
            step++;
        }
        
        return step;
    }
};