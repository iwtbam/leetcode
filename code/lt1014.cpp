// https://leetcode-cn.com/problems/best-sightseeing-pair/
// best sightseeing pair
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        deque<int> q;
        size_t size = A.size();
        for(int i = 0; i < size; i++){
            while(q.size() && A[i] - i > A[q.back()] - q.back()){
                q.pop_back();
            }
            q.push_back(i);
        }
        int res = 0;
        for(int i = 0; i < size - 1; i++){
            while(q.size() && q.front() <= i){
                q.pop_front();
            }
            res = max(res, A[i] + i + A[q.front()] - q.front());
        }

        return res;
    }
};