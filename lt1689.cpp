// https://leetcode-cn.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
// partitioning into minimum number of deci binary numbers
class Solution {
public:
    int minPartitions(string n) {
        int total = 0;
        size_t len = n.size();
        for(int i = 0; i < len; i++)
            total = max(total, n[i] - '0');
        return total;
    }
};