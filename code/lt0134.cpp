#include <vector>
#include <utility>

using namespace std;

//看看数学证明

class Solution{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int total_tank = 0;
        int curr_tank = 0;
        int start_pos = 0;
        for(int i = 0; i < size; i++){
            total_tank += gas[i] - cost[i];
            curr_tank += gas[i] - cost[i];
            if(curr_tank < 0)
            {
                curr_tank = 0;
                start_pos = start_pos + 1;
            }
        }

        return total_tank > 0 ? start_pos : -1;
    }
};