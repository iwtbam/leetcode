// https://leetcode-cn.com/problems/subrectangle-queries/
// subrectangle queries
class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        matrix = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i = row1; i <= row2; i++){
            for(int j = col1; j <= col2; j++){
                matrix[i][j] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return matrix[row][col];
    }
private:
    vector<vector<int>> matrix;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */