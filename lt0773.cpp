// https://leetcode-cn.com/problems/sliding-puzzle/
// sliding puzzle
struct State
{
    int r;
    int c;
    string s;
    int cost;
    State() = default;
    State(int r, int c, string s, int cost):r(r), c(c), s(s), cost(cost) {};
};

namespace std {
    template<>
    struct less<State>
    {
        bool operator ()(const State& s1, const State& s2)
        {
            return s1.cost > s2.cost;
        }
    };
};


class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string s(6, '0');
        int r, c;
        for(int i = 0; i < 6; i++)
        {
            s[i] = board[i / 3][i % 3] + '0';
            if(s[i] == '0'){
                r = i / 3;
                c = i % 3;
            }
        }
        
        cost[s] = 0;
        fcost[s] = f(s);
        int rows = 2, cols = 3;        
        priority_queue<State> q;

        q.emplace(r, c, s, cost[s] + fcost[s]);

        while(q.size())
        {
            auto [cr,cc, cs, ccost] = q.top();
            if(cs == "123450")
                return cost[cs];
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int nr = cr + dxs[i];
                int nc = cc + dys[i];
                if(nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                    continue;

                string ns = cs;
                ns[cr * 3 + cc] = cs[nr * 3 + nc];
                ns[nr * 3 + nc] = cs[cr * 3 + cc];

                if(fcost.count(ns) == 0)
                    fcost[ns] = f(ns);

                if(cost.count(ns) == 1 && cost[cs] + 1 + fcost[cs] > cost[ns] + fcost[ns])
                    continue;
                
                cost[ns] = cost[cs] + 1;
                
            

                q.emplace(nr, nc, ns, cost[ns] + fcost[ns]);
            }
        }

        return -1;
    }

    int f(const string& s)
    {
        int cost = 0;
        for(int i = 0; i < 6; i++)
        {
            int num = (s[i] - '0' + 5) % 6;
            cost += abs(num / 3 - i / 3) + abs(num % 3 - i % 3);
        }
        return cost;
    }

private:
    unordered_map<string, int> cost;
    unordered_map<string, int> fcost;
    int dxs[4] = {0, 0, 1, -1};
    int dys[4] = {1, -1, 0, 0};
};