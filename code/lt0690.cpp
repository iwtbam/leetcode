// https://leetcode-cn.com/problems/employee-importance/
// employee importance
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        size_t size = employees.size();
        unordered_map<int, Employee*> graph;
        for(int i = 0; i < size; i++)
            graph[employees[i]->id] = employees[i];

        queue<int> q;
        q.push(id);
        int res = 0;
        while(q.size())
        {
            int f = q.front();
            q.pop();
            Employee* e = graph[f];
            res += e->importance;
            for(int next : e->subordinates)
                q.push(next);
        }
        return res;    
    }
};