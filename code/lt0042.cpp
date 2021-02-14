#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

#define S2

#if defined (S1)

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int sum = 0;
        for(int i = 0; i < size; i++)
        {
            int max_left = 0, max_right = 0;
            
            for(int j = i; j >= 0; j--)
                max_left = max(max_left, height[j]);
            for(int j = i; j < size; j++)
                max_right = max(max_right, height[j]);
            
            sum += min(max_left, max_right) - height[i];
        }
        return sum;
    }
};


#elif defined (S2)

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        
        if(size == 0)
            return 0;

        int sum = 0;

        vector<int> leftmax(size, 0);
        vector<int> rightmax(size, 0);

        leftmax[0] = height[0];

        for(int i = 1; i < size; i++)
            leftmax[i] = max(leftmax[i-1], height[i]);

        rightmax[size-1] = height[size-1];

        for(int i = size - 2; i >=0; i--)
            rightmax[i] = max(rightmax[i+1], height[i]);

        for(int i = 0; i < size; i++)
            sum += min(leftmax[i], rightmax[i]) - height[i];
        
        return sum;
    }
};


#else

#endif