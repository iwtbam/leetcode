// https://leetcode-cn.com/problems/range-sum-query-2d-mutable/
// range sum query 2d mutable
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        if(rows == 0)
            return;
        cols = matrix[0].size();
        //this->matrix = matrix;
        this->matrix.resize(rows, vector<int>(cols, 0));
        trees.resize(rows + 1, vector<int>(cols + 1, 0));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                update(i, j, matrix[i][j]);
            }
        }
    }
    
    int lowbit(int x){
        return x & (-x);
    }

    void update(int row, int col, int val) {
        int diff = val - matrix[row][col];
        matrix[row][col] = val;
        row = row + 1; 
        col = col + 1;
        
        for(int r = row; r <= rows; r += lowbit(r)){
            for(int c = col; c <= cols; c += lowbit(c)){
                trees[r][c] += diff;
            }
        }
    }

    int sum(int row, int col){
        row = row + 1;
        col = col + 1;
        int res = 0;
        for(int r = row; r > 0; r -= lowbit(r)){
            for(int c = col; c > 0; c -= lowbit(c)){
                res += trees[r][c];
            }
        }
        return res;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum(row2, col2) - sum(row2, col1 - 1) - sum(row1 - 1, col2) + sum(row1 - 1, col1 - 1);
    }

private:
    vector<vector<int>> trees;
    vector<vector<int>> matrix;
    int rows, cols;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */