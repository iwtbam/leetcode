// https://leetcode-cn.com/problems/furthest-building-you-can-reach/
// furthest building you can reach
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {   
        size_t n = heights.size();
        
        priority_queue<int> q;

        for(int i = 1; i < n; i++){
            int diff = heights[i] - heights[i - 1] > 0 ? heights[i] - heights[i - 1] : 0;

            if(diff > 0){
                q.push(diff);
                bricks -= diff;   
            }

            while(bricks < 0 && q.size() && ladders){
                bricks += q.top();
                ladders--;
                q.pop();
            }

            if(bricks < 0)
                return i - 1;
        }

        return n - 1;
    }
};