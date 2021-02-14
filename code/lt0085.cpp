#include <vector>
#include <stack>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows == 0)
            return 0;
        int cols = matrix[0].size();

        vector<vector<int>> records = {cols, vector<int>(rows, 0)};

        for(int j = 0; j < rows; j++)
        {
            records[0][j] = matrix[j][0] - '0';
            for(int i = 1; i < cols; i++)
                records[i][j] = matrix[j][i] == '1' ? records[i - 1][j] + 1 : records[i][j];
        }
     

        int area = maxArea(records[0]);
        for(int i = 1; i < cols; i++)
            area = max(area, maxArea(records[i]));

        return area;
    }


    int maxArea(const vector<int>& widths){
        
        stack<int> is;
        is.push(-1);
        int size = widths.size();
        int area = 0;
        for(int i = 0 ; i < size; i++)
        {
            while(is.top()!=-1 && widths[is.top()] > widths[i]){
                int top = is.top();
                is.pop();
                area = max(area, (i - is.top() - 1) *widths[top]);
            }
            is.push(i);
        }

        while(is.top()!=-1)
        {
            int top = is.top();
            is.pop();
            area = max(area, (size - is.top() - 1) * widths[top]);
        }

        return area;
    }
};