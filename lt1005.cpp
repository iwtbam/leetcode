#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int neg_num = 0, size = A.size();
        sort(A.begin(), A.end());
        for(int i = 0; i < size; i++){
            if(A[i] < 0)
                neg_num++;
        }
        
        int res = 0;

        if(K > neg_num){
            int min_abs = INT_MAX;
            
            for(int i = 0; i < size; i++){
                min_abs = min(abs(A[i]), min_abs);
                res += abs(A[i]);
            }

            if((K - neg_num)%2)
                res -= min_abs * 2;

        }else{
            for(int i = 0; i < size; i++){
                if(K){
                    res += abs(A[i]);
                    K--;
                }
                else
                    res += A[i];
            }
        }

        return res;
         
    }
};