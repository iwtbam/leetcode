// https://leetcode-cn.com/problems/average-waiting-time/
// average waiting time
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        size_t size = customers.size();
        
        double cost = 0;
        
        int time = 0;
        
        for(int i = 0; i < size; i++){
            vector<int>& customer = customers[i];
            time = max(time + customer[1], customer[0] + customer[1]);
            cost += time - customer[0];
        }
        
        return cost / size;
    }
};