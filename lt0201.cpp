class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
       int offset = 0;
       
       while(m!=n && m!=0)
       {
           m = m >> 1;
           n = n >> 1;
           offset++;
       }

       return m << offset;
    }
};