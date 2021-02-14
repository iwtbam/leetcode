// https://leetcode-cn.com/problems/flatten-2d-vector/
// flatten 2d vector
class Vector2D {
public:
    Vector2D(vector<vector<int>>& v) {
        datas = v;
        while(rows < datas.size() && cols >= datas[rows].size())
            rows++;
    }
    
    int next() {
        int val = datas[rows][cols];
        ++cols;

        while(rows < datas.size() && cols  >= datas[rows].size()){
            ++rows;
            cols = 0;
        }
        return val;
    }
    
    bool hasNext() {
        if(rows >= datas.size())
            return false;

        if(rows == datas.size() && cols >= datas[rows].size())
            return false;

        return true;
    }

private:
    int rows = 0;
    int cols = 0;
    vector<vector<int>> datas;

};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */