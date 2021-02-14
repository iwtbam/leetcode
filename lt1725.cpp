// https://leetcode-cn.com/problems/number-of-rectangles-that-can-form-the-largest-square/
// number of rectangles that can form the largest square
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int max_edge = 0, num = 1;
        size_t n = rectangles.size();
        for(int i = 0; i < n; i++){
            int edge = min(rectangles[i][0], rectangles[i][1]);
            if(edge >= max_edge){
                if(edge == max_edge){
                    num = num + 1;
                }else{
                    max_edge = edge;
                    num = 1;
                }
            }
        }
        return num;
    }
};