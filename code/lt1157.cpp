// https://leetcode-cn.com/problems/online-majority-element-in-subarray/
// online majority element in subarray
struct Node {
    int val;
    int count;   
    Node(int val = 0, int count = 0):val(val), count(count){}
};

 Node operator+(const Node& n1, const Node& other){
        Node res = n1;
        if(res.val == other.val){
            res.count += other.count;
        }else if(res.count >  other.count){
            res.count -= other.count;
        }else{
            res.val = other.val;
            res.count = other.count - res.count;
        }
        return res;
 }

class MajorityChecker {
public:

    void build(int root, int l, int r, vector<int>& nums){
        if(l == r){
            segments[root] = {nums[l], 1};
            return;
        }

        int mid = l + (r - l) / 2;
        build(root * 2 + 1, l, mid, nums);
        build(root * 2 + 2, mid + 1, r, nums);
        segments[root] = segments[root * 2 + 1] + segments[root * 2 + 2];
        return;
    }

    Node query(int root, int l, int r, int ql, int qr){
        if(qr < l || ql > r)
            return {0, 0};
        if(ql <= l && r <= qr){
            return segments[root];
        } 
        int mid = l + (r - l) / 2;
        return query(root * 2 + 1, l, mid, ql, qr) + query(root * 2 + 2, mid + 1, r, ql, qr);
    }

    MajorityChecker(vector<int>& arr) {
        pos.resize(20001, vector<int>());
        int size = arr.size();
        R = size - 1;
        L = 0;
        segments.resize(size * 4, Node(0, 0));
        build(0, L, R, arr);
        for(int i = 0; i < size; i++){
            pos[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        auto [target, count] = query(0, L, R, left, right);
        if(count >= threshold)
            return target;
        int num = upper_bound(pos[target].begin(), pos[target].end(), right) - lower_bound(pos[target].begin(), pos[target].end(), left);
        if(num >= threshold)
            return target;
        return -1;
    }

private:
   vector<vector<int>> pos;
   vector<Node> segments;
   int L, R;
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */