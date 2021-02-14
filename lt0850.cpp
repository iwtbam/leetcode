// https://leetcode-cn.com/problems/rectangle-area-ii/
// rectangle area ii
struct SegmentNode
{
    int l;
    int r;
    int cnt;
    long long len;
};

struct Line
{
    int x, y1, y2, c;
    bool operator < (const Line& rhs){
       return x < rhs.x;
    }
};

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        size_t n = rectangles.size();
        for(int i = 1; i <= n; i++){
            auto& rect = rectangles[i - 1];
            lines[i * 2 - 1] = {rect[0], rect[1], rect[3], 1};
            lines[i * 2] = {rect[2], rect[1], rect[3], -1};
            raws[i * 2] = rect[1];
            raws[i * 2 - 1] = rect[3]; 
        }

        sort(lines + 1, lines + n * 2 + 1);
        sort(raws + 1, raws + n * 2 + 1);

        int cnt = unique(raws + 1, raws + n * 2 + 1) - raws - 1;
        build(1, 1, cnt);
        long long ans = 0;
        for(int i = 1; i <= n * 2; i++){
            int p = lower_bound(raws + 1, raws + cnt + 1, lines[i].y1) - raws;
            int q = lower_bound(raws + 1, raws + cnt + 1, lines[i].y2) - raws - 1;
            change(1, p, q, lines[i].c);
            ans = (ans + (nodes[1].len * (lines[i + 1].x - lines[i].x)) % MOD) % MOD;  
        }

        return ans;
    }

    void build(int no, int l ,int r)
    {
        nodes[no] = {l, r, 0, 0};
        if(nodes[no].l == nodes[no].r)
            return;
        int mid = (l + r) / 2;
        build(no << 1, l, mid);
        build(no << 1 | 1, mid + 1, r);
        return;
    }

    void change(int no, int l, int r, int v)
    {
        if(l <= nodes[no].l && nodes[no].r <= r)
        {
            nodes[no].cnt += v;
            merge(no);
            return;
        }

        int mid = (nodes[no].l + nodes[no].r) / 2;
        if(l <= mid)
            change(no << 1, l, r, v);
        if(r > mid)
            change(no << 1 | 1, l, r, v);
        merge(no);
    }

    void merge(int no){
        if(nodes[no].cnt > 0){
            nodes[no].len = raws[nodes[no].r + 1] - raws[nodes[no].l];
        }else if(nodes[no].l == nodes[no].r){
            nodes[no].len = 0;
        }else{
            nodes[no].len = (nodes[no << 1].len + nodes[no << 1 | 1].len) % MOD;
        }
    }

private:
    static const int N = 1000;
    const int MOD = 1e9 + 7;
    SegmentNode nodes[N * 4];
    Line lines[N * 2];
    int raws[N * 2];
};