#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int>& areas)
    {
        stack<int> is;
        is.push(-1);
        
        int max_area = 0;
        areas.push_back(-1);
        int size = areas.size();
        
        for(int i = 0; i < size; i++){
            int top_ele = is.top();
            if(top_ele != -1 && areas[i] < areas[top_ele])
            {  
                while(top_ele!=-1 && (areas[i] < areas[top_ele])){
                    is.pop();
                    int last_pos = is.top();
                    max_area = max(max_area, (i - last_pos - 1) * areas[top_ele]);
                    top_ele = last_pos;
                }
            }

            is.push(i);
        }

        return max_area;
    }
};