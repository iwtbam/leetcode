// https://leetcode-cn.com/problems/delivering-boxes-from-storage-to-ports/
// delivering boxes from storage to ports
class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        size_t n = boxes.size();
        vector<int> neg(n + 1, 0), w(n + 1, 0), p(n + 1, 0);
        vector<long long> W(n + 1, 0);

        for(int i = 1; i <= n; i++){
            p[i] = boxes[i - 1][0];
            w[i] = boxes[i - 1][1];
            if(i > 1){
                neg[i] = neg[i - 1] + (p[i] != p[i - 1]);
            }
            W[i] += W[i - 1] + w[i];
        }

        deque<int> q = {0};

        vector<int> f(n + 1, 0), g(n + 1, 0);

        for(int i = 1; i <= n; i++){
            while(q.size() && i - q.front() > maxBoxes || W[i] - W[q.front()] > maxWeight){
                q.pop_front();
            }

            f[i] = g[q.front()] + neg[i] + 2;
            if(i != n){
                g[i] = f[i] - neg[i + 1];
                while(q.size() && g[i] <= g[q.back()]){
                    q.pop_back();
                }
                q.push_back(i);
            }
        }

        return f[n];
    }
};