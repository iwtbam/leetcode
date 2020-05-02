class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) { 
        array<int, 26> count = {};

        int size = tasks.size();
        for(int i = 0; i < size; i++){
            count[tasks[i] - 'A']++;
        }

        sort(count.begin(), count.end());

        int max_val = count[25] - 1;
        int idle_slot = max_val * n;

        for(int i = 0; i < 25; i++){
            idle_slot -= min(count[i], max_val); 
        }

        return idle_slot > 0 ? idle_slot + tasks.size() : tasks.size();
    }
};