// https://leetcode-cn.com/problems/jump-game-iii/
// jump game iii
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int size = arr.size();
        vector<int> visited(size, 0);
        queue<int> q = {};
        q.push(start);
        visited[start] = 1;
        while(q.size()){
            int cur = q.front();
            q.pop();
            if(arr[cur] == 0)
                return true;
            int right = cur + arr[cur];
            int left  = cur - arr[cur];
            if(right < size && visited[right] == 0){
                q.push(right);
                visited[right] = 1;
            }

            if(left >= 0 && visited[left] == 0){
                q.push(left);
                visited[left] = 1;
            }
        }

        return false;
    }
};