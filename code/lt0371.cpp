class Solution {
public:
    int getSum(int a, int b) {
        int s1 = a ^ b;
        int s2 = a & b;
        while(s2){
            int s3 = s1  ^ (static_cast<unsigned>(s2) << 1);
            s2 = s1  & (static_cast<unsigned>(s2) << 1);
            s3 = s1;
        }
        return s1;
    }
};