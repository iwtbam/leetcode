// https://leetcode-cn.com/problems/rotate-matrix-lcci/
// rotate matrix lcci

ostream& operator << (ostream& os, const vector<vector<int>>& data){
    int rows = data.size();
    if(rows == 0)
        return os;
    int cols = data[0].size();
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            os << data[i][j] << " ";
        }
        os << endl;
    }
    return os;
}


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N / 2;j++){
                swap(matrix[i][j], matrix[i][N - j - 1]);
            }
        }
    }

    void swap(int& a, int& b){
        int temp = b;
        b = a;
        a = temp;
    }
};