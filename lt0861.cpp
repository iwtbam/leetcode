#include <vector>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int rows = A.size();
        int cols = A[0].size();
        
        for(int i = 0; i < rows; i++){
            if(A[i][0] == 1)
                continue;
            for(int j = 0; j < cols; j++){
                A[i][j] = 1 - A[i][j];
            }
        }

        for(int j = 0; j < cols; j++){
            int one_num = 0;
            for(int i = 0; i < rows; i++)
                one_num += A[i][j];
            
            if(one_num > rows / 2)
                continue;

            for(int i = 0; i < rows; i++)
                A[i][j] = 1 - A[i][j];
        }

        int res = 0;

        for(int i = 0; i < rows; i++){
            int row_val = 0;
            for(int j = 0; j < cols; j++){
                // cout << A[i][j] << " ";
                row_val = row_val * 2 + A[i][j];
            }
            // cout << endl;
            res += row_val;
        }

        return res;
    }
};