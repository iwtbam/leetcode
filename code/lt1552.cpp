// https://leetcode-cn.com/problems/magnetic-force-between-two-balls/
// magnetic force between two balls
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        n = position.size();
        if(m == 2)
            return position[n - 1] - position[0];
        long long l = 1, r =position[n - 1] - position[0];
        while(l < r){
            long long mid = (l + r + 1) >> 1;
            if(calc(position, mid, m) >= m){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }

    int calc(const vector<int>& position, int mid, int m){
        int pre = position[0];
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(position[i] - pre >= mid){
                cnt++;
                pre = position[i];
            }
        }
        return cnt;
    }
private:
    int n;
};