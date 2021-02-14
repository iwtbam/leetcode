// https://leetcode-cn.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
// average salary excluding the minimum and maximum salary
class Solution {
public:
    double average(vector<int>& salary) {
        int min_e = *min_element(salary.begin(), salary.end());
        int max_e = *max_element(salary.begin(), salary.end());
        int sum = accumulate(salary.begin(), salary.end(), 0);
        return (sum - min_e - max_e) * 1.0 / (salary.size() - 2);
    }
};