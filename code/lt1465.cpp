// https://leetcode-cn.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
// maximum area of a piece of cake after horizontal and vertical cuts
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
       
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int hs = horizontalCuts.size(), vs = verticalCuts.size();
       
        
        long long diffH = 0, diffV = 0, preH = 0, preV = 0;
        
        for(int i = 0; i < hs; i++){
            diffH = max(diffH, horizontalCuts[i] - preH);
            preH = horizontalCuts[i];
        }
        
        for(int i = 0; i < vs; i++){
            diffV = max(diffV, verticalCuts[i] - preV);
            preV = verticalCuts[i];
        }
        
        return (diffH * diffV) % static_cast<int>(pow(10, 9) + 7);
    }
};