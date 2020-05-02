class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ops = 0;
        while(X < Y){
            ops++;
            if(Y % 2)
                Y++;
            else
                Y/=2;
        }

        return ops + (X - Y);
    }
};