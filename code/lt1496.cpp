// https://leetcode-cn.com/problems/path-crossing/
// path crossing
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool isPathCrossing(string path) {
        unordered_set<int> record;
        pair<int, int> cur = {0, 0};
        record.insert(0);
        size_t size = path.size();
        for(int i = 0; i < size; i++){
            char d = path[i];
            switch(d){
                case 'N':
                    cur.first += dx[0];
                    cur.second += dy[0];
                    break;
                case 'S':
                    cur.first += dx[1];
                    cur.second += dy[1];
                    break;
                case 'E':
                    cur.first += dx[2];
                    cur.second += dy[2];
                    break;
                case 'W':
                    cur.first += dx[3];
                    cur.second += dy[3];
                    break;
            }
            if(record.count(cur.first * 10000 + cur.second))
                return true;
            record.insert(cur.first * 10000 + cur.second);
        }
        
        return false;
    }
    
};