// https://leetcode-cn.com/problems/container-with-most-water/
// container with most water
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = -INT_MAX;
        
        int l = 0;
        int r = height.size() - 1;
        
        while(l < r)
        {
            int w = r - l;
            int h = height.at(l) > height.at(r) ? height.at(r) : height.at(l);
            if(max_area < w * h)
                max_area = w * h;
            
            if(h == height.at(l))
                l++;
            else
                r--;
        }
        
        return max_area;
    }
};