// https://leetcode-cn.com/problems/circus-tower-lcci/
// circus tower lcci
struct Node 
{
    int h, w;
};

class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        size_t n = height.size();
        vector<Node> elements(n);
        
        for(int i = 0; i < n; i++){
            elements[i].h = height[i];
            elements[i].w = weight[i];
        }

        auto cmp1 = [](const Node& lhs, const Node& rhs){
           return lhs.h < rhs.h || (lhs.h == rhs.h && lhs.w > rhs.w);
        };
        
        auto cmp2 = [](const Node& lhs, const Node& rhs){
            return lhs.h < rhs.h && lhs.w < rhs.w;
        };

        sort(elements.begin(), elements.end(), cmp1);

        Node max_pair = {INT_MAX, INT_MAX};
        vector<Node> v(n + 1, max_pair); 
        for(int i = 0; i < n; i++){
            int pos = lower_bound(v.begin(), v.end(), elements[i], cmp2) - v.begin();
            v[pos] = elements[i];
        }

        return lower_bound(v.begin(), v.end(), max_pair, cmp2) - v.begin();
    }
};