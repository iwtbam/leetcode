#include <vector>

using namespace std;

class Solution {
public:
    
    int totalNQueens(int n) {
        vector<int> rows(n, 0);
        vector<int> d1(2*n, 0);
        vector<int> d2(2*n, 0);
        return helper(rows, d1, d2, 0, n);
    }
    
    int helper(vector<int>& rows, vector<int>& d1, vector<int>& d2, int step, int n){
        if(step == n){
            return 1;
        }
        
        int count = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(rows[i]==0 && d1[i + step]==0 && d2[step - i + n - 1]==0)
            {
                rows[i]=1;
                d1[i+step]=1;
                d2[step-i+n-1]=1;
                count += helper(rows, d1, d2, step+1, n);
                d2[step-i+n-1]=0;
                d1[i+step]=0;
                rows[i]=0;
            }
        }
        
        return count;
    }
      
};