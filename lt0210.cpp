#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> record = {numCourses, vector<int>()};
        vector<int> visited(numCourses, 0);
        vector<int> res = {};
        
        for(auto& pre: prerequisites)
        {
            record[pre[1]].push_back(pre[0]);
            visited[pre[0]]++;
        }
        
        queue<int> q;
        
        for(int i = 0; i < numCourses; i++)
        {
            if(visited[i] == 0)
                q.push(i);
        }
        
        if(q.size() == 0)
            return res;
        
        while(q.size())
        {
            int front = q.front();
            visited[front] = -1;
            res.push_back(front);
            
            q.pop();
            for(auto next:record[front])
            {
                visited[next]--;
                if(visited[next] == 0)
                    q.push(next);
            }
            
        }
        
        for(int i = 0; i < numCourses; i++)
        {
            if(visited[i] != -1)
                return {};
        }
        
        return res;
    }
};