#include <vector>

using namespace std;

inline void swap(int& a, int& b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        
        int mid = n / 2;
        for(int i = 0; i < mid; i++)
            for(int j = 0; j < n; j++)
                swap(matrix[j][i], matrix[j][n - i - 1]);
        
    }
};